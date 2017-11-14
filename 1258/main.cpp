//
//  main.cpp
//  1258
//
//  Created by 黄潮钦 on 2017/10/19.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//
#include <stdio.h>
#define max 1000001
long a[max],b[max];
long count;
void Merge(long a[], int start, int mid , int end)  //归并排序的合并部分
{
    int i = start,j = mid + 1,k = start;
    while(i <= mid&&j <= end)
    {
        if(a[i] <= a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            count += j - k;//统计逆序数对
            b[k++] = a[j++];
        }
    }
    while(i <= mid)
    {
        b[k++] = a[i++];
    }
    while(j <= end)
    {
        b[k++] = a[j++];
    }
    for(int i = start; i <= end; i++)
    {
        a[i] = b[i];
    }
}

void MergeSort(long a[], int start, int end)  //归并排序
{
    if(start < end)
    {
        int mid = (start + end)/2;
        MergeSort(a,start,mid);     // 将前半部分排序
        MergeSort(a,mid+1,end);     // 将后半部分排序
        Merge(a,start,mid,end);     // 合并前后两个部分
    }
}
int main(int argc, char const *argv[])
{
    int m;
    //scanf("%d",&n);
    //while(n--)
    //{
        scanf("%d",&m);
        count = 0;
        for(int i = 0; i < m; i++)
        {
            scanf("%ld",a+i);
        }
        MergeSort(a,0,m-1);
        printf("%ld\n",count);
    //}
    return 0;
}

/*
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;

const int maxn=500005;
int n;
int aa[maxn]; //离散化后的数组
int c[maxn];    //树状数组

struct Node{
    int v;
    int order;
}in[maxn];

int lowbit(int x)
{
    return x&(-x);
}

void update(int t,int value)
{
    int i;
    for(i=t;i<=n;i+=lowbit(i))
    {
        c[i]+=value;
    }
}

int getsum(int x)
{
    int i;
    int temp=0;
    for(i=x;i>=1;i-=lowbit(i))
    {
        temp+=c[i];
    }
    return temp;
}

bool cmp(Node a ,Node b)
{
    return a.v<b.v;
}

int main()
{
    int i,j;
    //while(scanf("%d",&n)==1 && n)
    //{
        //离散化
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        {
            scanf("%d",&in[i].v);
            in[i].order=i;
        }
        sort(in+1,in+n+1,cmp);
        for(i=1;i<=n;i++) aa[in[i].order]=i;
        //树状数组求逆序
        memset(c,0,sizeof(c));
        long long ans=0;
        for(i=1;i<=n;i++)
        {
            update(aa[i],1);
            ans+=i-getsum(aa[i]);
        }
    printf("%lld\n",ans);
        //cout<<ans<<endl;
    //}
    return 0;
} 
*/
