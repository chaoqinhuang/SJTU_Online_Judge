//
//  main.cpp
//  1215
//
//  Created by 黄潮钦 on 2017/10/26.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

template<class Type>
class priorityQueue
{
public:
    priorityQueue(int capacity=100001)
    {array=new Type[capacity];maxSize=capacity;currentSize=0;}
    priorityQueue(const Type data[],int size);
    ~priorityQueue(){delete [] array;}
    
    bool isEmpty() const{return currentSize==0;}
    void enQueue(const Type &x);
    Type deQueue();
    Type getHead()const{return array[1];}
    
    int findMin(Type x){
        Type Min=-1;
        int ID=-1;
        for(int i=1;i<=currentSize;++i)
            if(array[i]>=x&&(Min==-1||array[i]<Min)){
                Min=array[i];
                ID=i;
            }
        return ID;
    }
    
    void decreaseKey(int i,Type value){
        Type x;
        int hole=i;
        array[hole]-=value;
        for(x=array[i];hole>1&&x<array[hole/2];hole/=2)
            array[hole]=array[hole/2];
        array[hole]=x;
    }
    
    
private:
    int currentSize;
    Type *array;
    int maxSize;
    
    void doubleSpace();
    void buildHeap();
    void percolateDown(int hole);
};

template<class Type>
void priorityQueue<Type>::enQueue(const Type &x)
{
    if(currentSize==maxSize-1) doubleSpace();
    int hole=++currentSize;
    for(;hole>1&&x<array[hole/2];hole/=2)
        array[hole]=array[hole/2];
    array[hole]=x;
}

template<class Type>
Type priorityQueue<Type>::deQueue()
{  Type minItem;
    minItem=array[1];
    array[1]=array[currentSize--];
    percolateDown(1);
    return minItem;
}

template<class Type>
void priorityQueue<Type>::percolateDown(int hole)
{  int child;
    Type tmp=array[hole];
    for(;hole*2<=currentSize;hole=child)
    {  child=hole*2;
        if(child!=currentSize&&array[child+1]<array[child])
            child++;
        if(array[child]<tmp) array[hole]=array[child];
        else break;
    }
    array[hole]=tmp;
}

template<class Type>
void priorityQueue<Type>::buildHeap()
{  for(int i=currentSize/2;i>0;i--)
    percolateDown(i);
}

template<class Type>
priorityQueue<Type>::priorityQueue(const Type *items,int size)
:maxSize(size+10),currentSize(size)
{  array=new Type[maxSize];
    for(int i=0;i<size;i++)array[i+1]=items[i];
    buildHeap();
}

template<class Type>
void priorityQueue<Type>::doubleSpace()
{  Type *tmp=array;
    maxSize*=2;
    array=new Type[maxSize];
    
    for(int i=0;i<currentSize;++i) array[i]=tmp[i];
    delete [] tmp;
}

int main(){
    int M; scanf("%d",&M);
    string s;
    priorityQueue<int> q;
    for (int i = 0; i < M; i++){
        cin >> s;
        if (s[0] == 'i'){
            int num; scanf("%d\n",&num);//cin >> num;
            q.enQueue(num);
        }
        else if (s[0] == 'd'){
            q.deQueue();
        }
        else if (s[0] == 'm'){
            printf("%d\n",q.getHead());// << endl;
        }
        else continue;
    }
    
    //int j; cin >> j;
    return 0;
}
