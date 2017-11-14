//
//  main.cpp
//  1535
//
//  Created by 黄潮钦 on 2017/10/12.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include <iostream>
#include <cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int k,p,q,l,r,n=0;
int ans[110000];
int shuwei(int x)
{
    int sum=0;
    while (x>0)
    {
        sum+=x%10;
        x/=10;
    }
    return sum;
}
int main()
{
    scanf("%d%d%d%d%d",&k,&p,&q,&l,&r);
    for (int s=1;s<=81;++s)
    {
        long long x=p;
        for (int i=1;i<=k;++i)
            x*=s;
        x+=q;
        if ((x>=l)and(x<=r)and(shuwei((int)x)==s))
            ans[++n]=x;
    }
    sort(ans+1,ans+n+1);
    printf("%d\n",n);
    if(n==0){cout<<"-1";return 0;}
    for (int i=1;i<=n;++i)
        printf("%d ",ans[i]);
    return 0;
}
