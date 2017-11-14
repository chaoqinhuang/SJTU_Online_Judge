//
//  main.cpp
//  1570
//
//  Created by 黄潮钦 on 2017/9/28.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

/*#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int love[100001];
    int all[100001];
    int num[100001];
    int num_finish[100001];
    int a,b,aa=0;
    cin>>a>>b;
    for(int i=0;i<b;i++){num[i]=0;
    for(int i=0;i<a;i++)cin>>all[i];
    for(int i=0;i<b;i++)cin>>love[i];
 
    
    
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){if((all[i]>love[j])&&((a-i)>num[j]))num[j]=a-i;}
    }
    
    for(int i=0;i<b;i++)cout<<num[i]<<endl;
    return 0;
}
*/

/**
 hdu4417  树状数组（求指定区间比指定数小的数的个数）
 http://blog.csdn.net/wmn_wmn/article/details/8034181
 */
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=300005;

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

        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&a[i].num);
            a[i].id=i+1;
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&b[i].l,&b[i].r,&b[i].value);
            b[i].l++;
            b[i].r++;
            b[i].id=i+1;
        }
        sort(a,a+n);
        sort(b,b+m);
        memset(C,0,sizeof(C));
        int k=0;
        for(int i=0;i<m;i++)
        {
            while(k<n&&a[k].num<=b[i].value)
            {
                add(a[k].id,1);
                k++;
            }
            ans[b[i].id]=sum(b[i].r)-sum(b[i].l-1);
        }
        //printf("Case %d:\n",++tt);
        for(int i=1;i<=m;i++)
        {
            printf("%d\n",ans[i]);
        }
    return 0;
}


