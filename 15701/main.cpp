//
//  main.cpp
//  15701
//
//  Created by 黄潮钦 on 2017/9/29.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=100001;

int C[maxn],ans[maxn];
int n,m;

int lowbit(int x)
{
    return x&(-x);
}

int sum(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=C[x];
        x-=lowbit(x);
    }
    return ret;
}

void add(int x,int d)
{
    while(x<=n)
    {
        C[x]+=d;
        x+=lowbit(x);
    }
}

struct node
{
    int id,num;
    bool operator < (const node &other) const
    {
        return num < other.num;
    }
}a[maxn];
struct note
{
    int l,r,id,value;
    bool operator < (const note &other)const
    {
        return value <other.value;
    }
}b[maxn];

int main()
{
    int T,tt=0;
    //m=1;
    //int time=1;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&a[i].num);
        a[i].id=i+1;
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i].value);
        b[i].l=1;
        b[i].r=n;
        //b[i].l++;
        //b[i].r++;
        b[i].id=i+1;
    }
    //cout<<"11111"<<endl;
    sort(a,a+n);
    sort(b,b+m);
    memset(C,0,sizeof(C));
    int k=0;
    //cout<<"22222"<<endl;
    for(int i=0;i<m;i++)
    {
        while(k<n&&a[k].num<=b[i].value)
        {
            add(a[k].id,1);
            k++;
        }
        ans[b[i].id]=sum(b[i].r)-sum(b[i].l-1);
    }
    //cout<<"33333"<<endl;
    //printf("Case %d:\n",++tt);
    for(int i=1;i<=m;i++)
    {
        printf("%d\n",n-ans[i]);
    }
    return 0;
}
