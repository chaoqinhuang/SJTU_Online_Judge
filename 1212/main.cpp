//
//  main.cpp
//  1212
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

template <class Type>
class BinaryTree{
private:
    struct node{
        node *left,*right;
        Type data;
        
        node():left(NULL),right(NULL){}
        node(Type item,node *L=NULL,node *R=NULL):
        data(item),left(L),right(R){}
        ~node(){}
    };
    
    node *root;
    
public:
    struct elem{
        node *p;
        int num;
    };
    BinaryTree():root(NULL){}
    BinaryTree(const Type &value){root=new node(value);}
    ~BinaryTree(){clear();}
    
    Type getRoot()const{return root->data;}
    Type getLeft()const{return root->left->data;}
    Type getRight()const{return root->right->data;}
    
    void makeTree(const Type &x,BinaryTree &lt,BinaryTree &rt)
    {root=new node(x,lt.root,rt.root);
        lt.root=NULL;
        rt.root=NULL;
    }
    
    void deLeft()
    {clear(root->left);
        root->left=NULL;
    }
    
    void deRight()
    {clear(root->right);
        root->right=NULL;
    }
    
    bool isEmpty()const{return root==NULL;}
    void clear(){if(root!=NULL)clear(root);root=NULL;}
    int size()const{return size(root);}
    int height()const{return height(root);}
    
    void preOrder()const
    {if(root==NULL)return;
        //cout<<"\n«∞–Ú±È¿˙£∫";
        preOrder(root);
    }
    
    void postOrder()const
    {if(root==NULL)return;
        cout<<"\n∫Û–Ú±È¿˙£∫";
        postOrder(root);
    }
    
    void midOrder()const
    {if(root==NULL)return;
        cout<<"\n÷––Ú±È¿˙£∫";
        midOrder(root);
    }
    
    void createTree(int);
    
    void swaplr(){swaplr(root);}
    
    int countDegreeTwo(){return countDegreeTwo(root);}
    
    void depthTraverse(){
        linkQueue<node *>que;
        node *cur;
        
        //cout<<"≤„¥Œ±È¿˙£∫";
        if(root==NULL)return;
        
        que.enQueue(root);
        while(!que.isEmpty()){
            cur=que.deQueue();
            if(cur->left!=NULL)que.enQueue(cur->left);
            if(cur->right!=NULL)que.enQueue(cur->right);
            cout<<num[cur->data][2]<<' ';
        }
        cout<<endl;
    }
    
    bool isCompleteTree(){
        linkQueue<elem>que;
        elem cur,child;
        int count=1;
        int last=1;
        
        if(root==NULL)return true;
        cur.p=root;
        cur.num=1;
        que.enQueue(cur);
        while(!que.isEmpty()){
            cur=que.deQueue();
            if(cur.p->left!=NULL){
                ++count;
                child.p=cur.p->left;
                last=child.num=cur.num*2;
                que.enQueue(child);
            }
            if(cur.p->right!=NULL){
                ++count;
                child.p=cur.p->right;
                last=child.num=cur.num*2+1;
                que.enQueue(child);
            }
        }
        return count==last;
    }
    
    bool operator==(const BinaryTree<Type> &t2)
    {return checkEqual(this->root,t2.root);}
    
    void makeTreeFromOrder()
    {int a=0,m=-1,n=-1;
        char order1[20],order2[20];
        cout<<"»Ù∏˘æ›«∞–Ú±È¿˙∫Õ÷––Ú±È¿˙…˙≥… ˜£¨«Î ‰»Î1£ª"<<endl;
        cout<<"»Ù∏˘æ›÷––Ú±È¿˙∫Õ∫Û–Ú±È¿˙…˙≥… ˜£¨«Î ‰»Î2£ª"<<endl;
        cin>>a;
        if(a==1) {cout<<"«Î ‰»Î«∞–Ú±È¿˙£®“‘@Ω· ¯£©£∫";
            for(int i=0;i<20;i++){cin>>order1[i];m++;if(order1[i]=='@')break;}
            order1[m]=NULL;
            cout<<"«Î ‰»Î÷––Ú±È¿˙£®“‘@Ω· ¯£©£∫";
            for(int i=0;i<20;i++){cin>>order2[i];n++;if(order2[i]=='@')break;}
            order2[n]=NULL;
            root=preAndMid(order1,order2,0,m-1,0,n-1);}
        if(a==2) {cout<<"«Î ‰»Î÷––Ú±È¿˙£®“‘@Ω· ¯£©£∫";
            for(int i=0;i<20;i++){cin>>order1[i];m++;if(order1[i]=='@')break;}
            order1[m]=NULL;
            cout<<"«Î ‰»Î∫Û–Ú±È¿˙£®“‘@Ω· ¯£©£∫";
            for(int i=0;i<20;i++){cin>>order2[i];n++;if(order2[i]=='@')break;}
            order2[n]=NULL;
            root=midAndPost(order1,order2,0,n-1,0,m-1);}
    }
    
private:
    int height(node *t)const
    { if(t==NULL)return 0;
        int lt=height(t->left),rt=height(t->right);
        return 1+((lt>rt)?lt:rt);
    }
    
    void clear(node *t)
    { if(t->left!=NULL)clear(t->left);
        if(t->right!=NULL)clear(t->right);
        delete t;
    }
    
    int size(node *t)const
    { if(t==NULL)return 0;
        return 1+size(t->left)+size(t->right);
    }
    
    void preOrder(node *t)const
    {if(t==NULL)return;
        cout<<t->data<<' ';
        preOrder(t->left);
        preOrder(t->right);
    }
    
    void postOrder(node *t)const
    {if(t==NULL)return;
        postOrder(t->left);
        postOrder(t->right);
        cout<<t->data<<' ';
    }
    
    void midOrder(node *t)const
    {if(t==NULL)return;
        midOrder(t->left);
        cout<<t->data<<' ';
        midOrder(t->right);
    }
    
    void swaplr(node *n){
        node *p;
        if(n->left)swaplr(n->left);
        if(n->right)swaplr(n->right);
        
        p=n->left;
        n->left=n->right;
        n->right=p;
    }
    
    int countDegreeTwo(node *n){
        if(n==NULL)return 0;
        if(n->left&&n->right)
            return 1+countDegreeTwo(n->left)+countDegreeTwo(n->right);
        else
            return countDegreeTwo(n->left)+countDegreeTwo(n->right);
    }
    
    bool checkEqual(BinaryTree<Type>::node *t1,BinaryTree<Type>::node *t2)
    { if(t1==NULL&&t2==NULL)return true;
        if(t1==NULL||t2==NULL)return false;
        if(t1->data!=t2->data)return false;
        return checkEqual(t1->left,t2->left)&&checkEqual(t1->right,t2->right);
    }
    
    node *preAndMid(char *order1,char *order2,int i,int j,int k,int l)
    {int m;
        node *p;
        p=new node(order1[i],NULL,NULL);
        m=k;
        while(order2[m]!=order1[i]){m++;}
        if(m==k){p->left=NULL;}
        else {p->left=preAndMid(order1,order2,i+1,i+m-k,k,m-1);}
        if(m==l){p->right=NULL;}
        else{p->right=preAndMid(order1,order2,i+m-k+1,j,m+1,l);}
        return(p);
    }
    
    node *midAndPost(char *order1,char *order2,int i,int j,int k,int l)
    {int m;
        node *p;
        p=new node(order2[l],NULL,NULL);
        m=i;
        while(order1[m]!=order2[l]){m++;}
        if(m==i){p->left=NULL;}
        else {p->left=midAndPost(order1,order2,i,m-1,k,k+m-i-1);}
        if(m==j){p->right=NULL;}
        else{p->right=midAndPost(order1,order2,m+1,j,k+m-i,l-1);}
        return(p);
    }
    
};

template<class Type>
void BinaryTree<Type>::createTree(int rootnum)
{linkQueue<node * >que;
    node *tmp;
    Type x,ldata,rdata;
    
    //¥¥Ω® ˜£¨ ‰»Îflag±Ì æø’
    //cout<<"\n ‰»Î∏˘Ω⁄µ„£∫";
    //cin>>x;
    root=new node(rootnum);
    que.enQueue(root);
    
    while(!que.isEmpty()){
        tmp=que.deQueue();
        //cout<<"\n ‰»Î"<<tmp->data<<"µƒ¡Ω∏ˆ∂˘◊”("<<flag<<"±Ì æø’Ω⁄µ„):";
        //cin>>ldata>>rdata;
        ldata=num[tmp->data][0];
        rdata=num[tmp->data][1];
        if(ldata!=0)que.enQueue(tmp->left=new node(ldata));
        if(rdata!=0)que.enQueue(tmp->right=new node(rdata));
    }
    
    //cout<<"create completed!\n";
}
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    BinaryTree<int> tree1;
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
    tree1.depthTraverse();
    return 0;
}
