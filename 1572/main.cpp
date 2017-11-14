//
//  main.cpp
//  1572
//
//  Created by 黄潮钦 on 2017/9/29.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
#define N 1010
int c[N];
int n;
int lowbit(int i)
{
    return i&(-i);
}
int insert(int i,int x)
{
    while(i<=n){
        c[i]+=x;
        i+=lowbit(i);
    }
    return 0;
}

int getsum(int i)
{
    int sum=0;
    while(i>0){
        sum+=c[i];
        i-=lowbit(i);
    }
    return sum;
}
void output()
{
    for(int i=1;i<=n;i++) cout<<c[i]<<" ";
    cout<<endl;
}
int main()
{
    //while(cin>>n){
    cin>>n;
    int ans=0;
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++){
            int a;
            cin>>a;
            insert(a,1);
            ans+=i-getsum(a);//统计当前序列中大于a的元素的个数
            //cout<<ans<<endl;
        }
        cout<<ans<<endl;
    
    return 0;
}
