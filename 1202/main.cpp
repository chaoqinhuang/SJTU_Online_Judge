//
//  main.cpp
//  1202
//
//  Created by 黄潮钦 on 2017/9/22.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include <iostream>
using namespace std;

/*template<class T>
class LinkedList
{
private:
    struct node {
        T value;
        node *next;
        
        node():next(NULL){}
        node(const T &v,node *n=NULL):value(v),next(n){}
    };
    
    node *head;
    int size;
    
public:
    node *get(int i)const
    {
        if(i<0) return head;
        node *p=head->next;
        for(int j=0;j<i;++j) p=p->next;
        
        return p;
    }
    
    LinkedList():size(0)
    { head=new node;}
    
    ~LinkedList(){
        clear();
        delete head;
    }
    
    void clear()
    {while(length()>0)remove(0);
    }
    
    int length()const
    {return size;}
    
    void insert(int i,const T &x)
    {node *p=get(i-1);
        p->next=new node(x,p->next);
        ++size;
    }
    
    void remove(int i)
    { node *p=get(i-1);
        node *q=p->next;
        p->next = q->next;
        delete q;
        --size;
    }
    
    int search(const T &x)const
    {
        node *p=head->next;
        for(int i=0;p;++i){
            if(x==p->value)return i;
            p=p->next;
        }
        return -1;
    }
    
    T visit(int i)const
    {
        return get(i)->value;
    }
    
    void traverse()const
    {
        node *p=head->next;
        while(p){
            cout<<p->value<<'\t';
            p=p->next;
        }
    }
    
    void inverse(){
        if(head->next==NULL)return;
        node *cur=head->next->next;
        node *cur_next;
        head->next->next=NULL;
        while(cur!=NULL){
            cur_next=cur->next;
            cur->next=head->next;
            head->next=cur;
            cur=cur_next;
        }
    }
};
 */

class BigData{
    friend ostream &operator<<(ostream &os,const BigData &x);
    friend istream &operator>>(istream &is,BigData &x);
    friend BigData operator+(BigData a,BigData b);
private:
    struct node{
        int data;
        node *next;
        node(const short &x,node *n=NULL){data=x;next=n;}
        node():next(NULL){}
    };
    node *num;
    void clear();
    
public:
    BigData(node *p=NULL)
    {if(p==NULL)num=new node(0);else num=p;}
    BigData(const BigData &);
    ~BigData(){clear();}
    BigData &operator=(const BigData &);
};

BigData::BigData(const BigData &x){
    num = new node(x.num->data);
    node *p=num,*q=x.num;
    while(q->next!=NULL){
        q=q->next;
        p->next=new node(q->data);
        p=p->next;
    }
}

void BigData::clear(){
    node *p=num,*q;
    while(p!=NULL){
        q=p;
        p=p->next;
        delete q;
    }
    num=NULL;
}

BigData operator+(BigData a,BigData b)
{
    BigData tmp;
    BigData::node *p,*q,*end;
    int carry;
    
    tmp.num=end=new BigData::node(a.num->data+b.num->data);
    carry= tmp.num->data/10;
    tmp.num->data %=10;
    
    p=a.num->next;
    q=b.num->next;
    end=tmp.num;
    while(p!=NULL&&q!=NULL){
        end->next=new BigData::node(p->data+q->data+carry);
        end=end->next;
        carry=end->data/10;
        end->data%=10;
        p=p->next;
        q=q->next;
    }
    if(p==NULL)p=q;
    while(p!=NULL){
        end->next=new BigData::node(p->data+carry);
        end=end->next;
        carry=end->data/10;
        end->data%=10;
        p=p->next;
    }
    if(carry!=0)end->next=new BigData::node(carry);
    
    return tmp;
}

BigData &BigData::operator=(const BigData &x)
{
    if(&x==this)return *this;
    clear();
    num=new node(x.num->data);
    node *p=num,*q=x.num;
    while (q->next!=NULL) {
        
        q=q->next;
        p->next=new node(q->data);
        p=p->next;
    }
    return *this;
}

ostream &operator<<(ostream &os,const BigData &x)
{
    std::string s;
    BigData::node *p=x.num;
    while(p!=NULL){
        s=char(p->data+'0')+s;
        p=p->next;
    }
    for(int i=0;i<s.size();++i)os<<s[i];
    return os;
}

istream &operator>>(istream &is,BigData &x)
{
    char ch;
    x.clear();
    while((ch=is.get())!='\n'){
        x.num=new BigData::node(ch-'0',x.num);
    }
    return is;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    BigData a,b,ans;
    cin>>a;
    cin>>b;
    ans=a+b;
    cout<<ans;
    
    return 0;
}
