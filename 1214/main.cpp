//
//  main.cpp
//  1214
//
//  Created by 黄潮钦 on 2017/10/12.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include <iostream>
using namespace std;
int num[100000][3];
template<class elemType>
class queue
{public:
    virtual bool isEmpty()=0;
    virtual void enQueue(const elemType &x)=0;
    virtual elemType deQueue()=0;
    virtual elemType getHead()=0;
    virtual ~queue(){}
};

template<class elemType>
class linkQueue:public queue<elemType>
{private:
    struct node{
        elemType data;
        node *next;
        node(const elemType &x,node *N=NULL)
        {  data=x;next=N;}
        node():next(NULL){}
        ~node(){}
    };
    
    node *front,*rear;
    
public:
    linkQueue(){front=rear=NULL;}
    ~linkQueue();
    bool isEmpty(){return front==NULL;}
    void enQueue(const elemType &x);
    elemType deQueue();
    elemType getHead(){return front->data;}
};

template<class elemType>
linkQueue<elemType>::~linkQueue(){
    node *tmp;
    while(front!=NULL){
        tmp=front;
        front=front->next;
        delete tmp;
    }
}

template<class elemType>
void linkQueue<elemType>::enQueue(const elemType &x){
    if(rear==NULL)
        front=rear=new node(x);
    else{
        rear->next=new node(x);
        rear=rear->next;
    }
}

template<class elemType>
elemType linkQueue<elemType>::deQueue(){
    node *tmp=front;
    elemType value=front->data;
    front=front->next;
    if(front==NULL)rear=NULL;
    delete tmp;
    return value;
}

template <class T>
class tree {
    struct node {
        T data;
        node *son,*brother;
        node(T d,node *s=NULL,node *b=NULL)
        {data=d;son=s;brother=b;}
        node(){}
    };
    
    node *root;
    
public:
    tree(node *t=NULL){root=t;}
    void createTree(int);
    void preOrder(){preOrder(root);}
    void postOrder(){postOrder(root);}
    void levelOrder();
    
private:
    void preOrder(node *t);
    void postOrder(node *t);
};

template <class T>
void tree<T>::preOrder(node *t){
    if(t==NULL)return;
    cout<<num[t->data][2]<<' ';
    
    node *p=t->son;
    while(p!=NULL){
        preOrder(p);
        p=p->brother;
    }
}

template <class T>
void tree<T>::postOrder(node *t){
    if(t==NULL)return;
    
    
    node *p=t->son;
    while(p!=NULL){
        postOrder(p);
        p=p->brother;
    }
    cout<<num[t->data][2]<<' ';
}

template <class T>
void tree<T>::levelOrder(){
    linkQueue<node *>que;
    node *tmp;
    if(root==NULL)return;
    que.enQueue(root);
    while(!que.isEmpty()){
        tmp=que.deQueue();
        cout<<num[tmp->data][2]<<' ';
        tmp=tmp->son;
        while(tmp!=NULL){
            que.enQueue(tmp);
            tmp=tmp->brother;
        }
    }
}

template <class T>
void tree<T>::createTree(int rootnum){
    linkQueue<node *>que;
    node *tmp;
    T x,son;
    
    root=new node(rootnum);
    que.enQueue(root);
    while(!que.isEmpty()){
        tmp=que.deQueue();
        if(num[tmp->data][0]!=0){tmp->son=new node(num[tmp->data][0]);tmp=tmp->son;que.enQueue(tmp);}
        while(num[tmp->data][1]!=0){tmp->brother=new node(num[tmp->data][1]);tmp=tmp->brother;que.enQueue(tmp);}
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    tree<int> tree1;
    int n,rootnum;
    cin>>n;
    
    int time[100000];
    for(int i=1;i<=n;i++){time[i]=0;}
    for(int i=1;i<=n;i++)cin>>num[i][0]>>num[i][1]>>num[i][2];
    for(int i=1;i<=n;i++){time[num[i][0]]++;time[num[i][1]]++;}
    for(int i=1;i<=n;i++){if(time[i]==0){rootnum=i;break;}}
    //cout<<rootnum<<endl;
    tree1.createTree(rootnum);
    //tree1.preOrder();
    //if(tree1.isCompleteTree()==1)cout<<"Y"<<endl;else cout<<"N"<<endl;
    tree1.preOrder();
    cout<<endl;
    tree1.postOrder();
    cout<<endl;
    tree1.levelOrder();
    return 0;
}
