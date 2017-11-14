//
//  main.cpp
//  1569
//
//  Created by 黄潮钦 on 2017/9/29.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//
/* 功能Function Description:    HDOJ-1166 树状数组插点问线  、线段树解法
 开发环境Environment:            DEV C++ 4.9.9.1
 技术特点Technique:
 版本Version:
 作者Author:                  可笑痴狂
 日期Date:                    20120808
 备注Notes:
 */


 //代码一：----树状数组
 #include<stdio.h>
 #include<string.h>
 
 int n;
 int a[50005];
 
 int lowbit(int i)
 {
     return i&(-i);
 }
 
 void update(int i,int num){
     while(i<=n){
         a[i]+=num;
         i+=lowbit(i);
     }
 }
 
 int getsum(int i){
     int sum=0;
     while(i>0){
         sum+=a[i];
         i-=lowbit(i);
     }
     return sum;
 }
 
 int main()
 {
     int T,i,j,m;
     char cmd[10];
     
         //printf("Case %d:\n",m);
         memset(a,0,sizeof(a));
         scanf("%d",&n);
         for(i=1;i<=n;++i)
         {
             scanf("%d",&j);
             update(i,j);
         }
         while(scanf("%s",cmd))
         {
             if(cmd[0]=='i')
             {
                 scanf("%d%d",&i,&j);
                 update(i,j);
             }
             else if(cmd[0]=='q')
             {
                 scanf("%d%d",&i,&j);
                 printf("%d\n",getsum(j)-getsum(i-1));
             }
             else if(cmd[0]=='d')
             {
                 scanf("%d%d",&i,&j);
                 update(i,-j);
             }
             else
                 break;
         }
     
     return 0;
 }


//代码二：-------线段树
/*
#include<stdio.h>
#define MAX 50000

struct node
{
    int lc,rc;
    int sum;     //存放的是从lc到rc之间的总人数
}tree[MAX*3];

void build(int s,int t,int T)
{
    int mid=(s+t)>>1;
    tree[T].lc=s;
    tree[T].rc=t;
    tree[T].sum=0;
    if(s==t)
        return;
    build(s,mid,T<<1);
    build(mid+1,t,(T<<1)|1);
}

void insert(int num,int add,int T)    //编号为num的线段增加了add，从T开始查找，在含有num的线段中sum都加add
{
    if(num<tree[T].lc||num>tree[T].rc)
        return ;
    else
    {
        tree[T].sum+=add;
        if(tree[T].lc==tree[T].rc)
            return;
        if(num<=((tree[T].lc+tree[T].rc)>>1))
            insert(num,add,T<<1);
        else
            insert(num,add,(T<<1)|1);
    }
}

int getsum(int s,int t,int T)  //统计从s到t的总人数，从T开始查找知道找到该条线段为止
{
    int mid=(tree[T].lc+tree[T].rc)>>1;
    if(tree[T].lc==s&&tree[T].rc==t)
        return tree[T].sum;
    if(t<=mid)
        return getsum(s,t,T<<1);
    else if(s>mid)
        return getsum(s,t,(T<<1)|1);
    else
        return getsum(s,mid,T<<1)+getsum(mid+1,t,(T<<1)|1);
}


int main()
{
    int k,i,j,m,n,t;
    char cmd[10];
    scanf("%d",&k);
    for(m=1;m<=k;++m)
    {
        printf("Case %d:\n",m);
        scanf("%d",&n);
        build(1,n,1);
        for(i=1;i<=n;++i)
        {
            scanf("%d",&t);
            insert(i,t,1);
        }
        while(scanf("%s",cmd))
        {
            if(cmd[0]=='A')
            {
                scanf("%d%d",&i,&j);
                insert(i,j,1);
            }
            else if(cmd[0]=='Q')
            {
                scanf("%d%d",&i,&j);
                printf("%d\n",getsum(i,j,1));
            }
            else if(cmd[0]=='S')
            {
                scanf("%d%d",&i,&j);
                insert(i,-j,1);
            }
            else
                break;
        }
    }
    return 0;
}
*/
