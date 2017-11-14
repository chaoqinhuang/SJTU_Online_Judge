//
//  main.cpp
//  1203
//
//  Created by 黄潮钦 on 2017/9/22.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include <iostream>
using namespace std;

template<class elemType>
class seqList
{
    friend seqList operator+(const seqList<elemType>&a,const seqList<elemType>&b)
    {
            seqList<elemType>c(a.length()+b.length());
            int i=0;
            for(i=0;i<a.currentLength;++i)
                c.data[i]=a.data[i];
            for(int j=0;j<b.currentLength;++j)
                c.data[i++]=b.data[j];
            c.currentLength=i;
            return c;
    }
private:
    elemType *data;
    int currentLength;
    int maxSize;
    
    void doubleSpace();
public:
    seqList(int initSize=10);
    ~seqList(){delete [] data;}
    void clear(){currentLength=0;}
    int length()const{return currentLength;}
    void insert(int i,const elemType &x);
    void remove(int i);
    int search(const elemType &x)const;
    elemType visit(int i)const;
    void traverse()const;
    seqList &operator=(const seqList<elemType>&other);
    seqList(const seqList<elemType>&other)
    {
        currentLength=other.currentLength;
        maxSize=other.maxSize;
        data=new elemType[maxSize];
        for(int i=0;i<currentLength;++i)
            data[i]=other.data[i];
    }
};

template<class elemType>
void seqList<elemType>::doubleSpace()
{
    elemType *tmp=data;
    maxSize*=2;
    data=new elemType[maxSize];
    
    for(int i=0;i<currentLength;++i)data[i]=tmp[i];
    delete [] tmp;
}

template<class elemType>
seqList<elemType>::seqList(int initSize)
{
    data=new elemType[initSize];
    maxSize=initSize;
    currentLength=0;
}

template<class elemType>
void seqList<elemType>::insert(int i, const elemType &x)
{
    if(currentLength==maxSize)doubleSpace();
    for(int j=currentLength;j<i;j--)data[j]=data[j-1];
    data[i]=x;
    ++currentLength;
}

template<class elemType>
void seqList<elemType>::remove(int i)
{
    for(int j=i;j<currentLength;j++)data[j]=data[j+1];
    --currentLength;
}

template<class elemType>
int seqList<elemType>::search(const elemType &x)const
{
    int i=0;
    for(i=0;i<currentLength && data[i]!=x;i++);
    if(i==currentLength)return -1;else return i;
}

template<class elemType>
elemType seqList<elemType>::visit(int i)const
{
    return data[i];
}

template<class elemType>
void seqList<elemType>::traverse()const
{
    for(int i=0;i<currentLength;i++)cout<<data[i]<<' ';
}

/*template<class elemType>
seqList<elemType> operator+(const seqList<elemType>&a,const seqList<elemType>&b)
{
    seqList<elemType>c(a.length()+b.length());
    int i=0;
    for(i=0;i<a.currentLength;++i)
        c.data[i]=a.data[i];
    for(int j=0;j<b.currentLength;++j)
        c.data[i++]=b.data[j];
    c.currentLength=i;
    return c;
}
 */

template<class elemType>
seqList<elemType> &seqList<elemType>::operator=(const seqList<elemType>&other)
{
    if(this==&other)return *this;
    delete [] data;
    currentLength=other.currentLength;
    maxSize=other.maxSize;
    data=new elemType[maxSize];
    for(int i=0;i<currentLength;++i)
        data[i]=other.data[i];
    return *this;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char ch[10];
    cin>>ch;
    int aa,bb,num;
    double num1;
    char num2;
    cin>>aa>>bb;
    if(ch[0]=='i')
    {
        seqList<int> a;
        seqList<int> b;
        seqList<int> c;
        for(int i=0;i<aa;++i){cin>>num;a.insert(i,num);}
        for(int i=0;i<bb;++i){cin>>num;b.insert(i,num);}
        c=a+b;
        c.traverse();
    }
    if(ch[0]=='d')
    {
        seqList<double> a;
        seqList<double> b;
        seqList<double> c;
        for(int i=0;i<aa;++i){cin>>num1;a.insert(i,num1);}
        for(int i=0;i<bb;++i){cin>>num1;b.insert(i,num1);}
        c=a+b;
        c.traverse();
    }
    if(ch[0]=='c')
    {
        seqList<char> a;
        seqList<char> b;
        seqList<char> c;
        for(int i=0;i<aa;++i){cin>>num2;a.insert(i,num2);}
        for(int i=0;i<bb;++i){cin>>num2;b.insert(i,num2);}
        c=a+b;
        c.traverse();
    }
    return 0;
}
