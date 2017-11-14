//
//  main.cpp
//  1113
//
//  Created by 黄潮钦 on 2017/10/19.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
#include <math.h>
#define inf 0x3f3f3f3f
using namespace std;
long long c, n, f;
struct stu
{
    long long score, aid;
    bool operator <(const stu &oth)const
    {
        return aid < oth.aid;
    }
    
} a[123456];
bool cmp(stu a, stu b)
{
    return a.score >b.score;
}
int main()
{
    int i, j, k;
    cin >> n >> c >> f;
    for ( i = 0; i < c; i++)
    {
        cin >> a[i].score >> a[i].aid;
    }
    sort(a, a + c,cmp);
    long long mid,sum=0,sum1[123456],flag=1,sum2[123456],sum3;
    stu temp;
    priority_queue<stu>que;
    for(i=0;i<c;i++){
        if(que.size()==(n-1)/2){
            sum1[i]=sum;
        }else sum1[i]=inf;
        sum+=a[i].aid;
        que.push(a[i]);
        if(que.size()>(n-1)/2){
            sum-=que.top().aid;
            que.pop();
        }
    }
    priority_queue<stu>que2;
    sum=0;
    for(j=c-1;j>=0;j--){
        if(que2.size()==(n-1)/2){
            sum2[j]=sum;
        }else sum2[j]=inf;
        sum+=a[j].aid;
        que2.push(a[j]);
        if(que2.size()>(n-1)/2){
            sum-=que2.top().aid;
            que2.pop();
        }
    }
    for(i=(n-1)/2;i<=c-(n-1)/2-1;i++){
        flag=1;
        if(a[i].aid+sum1[i]+sum2[i]<=f){
            flag=0;
            cout<<a[i].score<<endl;
            break;
        }
    }
    if(flag)cout<<-1<<endl;
    return 0;
}
