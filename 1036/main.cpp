//
//  main.cpp
//  1036
//
//  Created by 黄潮钦 on 2017/9/22.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include <iostream>
using namespace std;

long long max(long long a,long long b,long long c)
{
    b=(b>c?b:c);
    return (a>b?a:b);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int people;
    cin>>people;
    int people1=people,serve1=0,serve2=1,serve3=2,serveend=3;
    int timea=0,timeb=0,timec=0;
    int total_time=0;
    int time[100001],time1[100001];
    for(int i=0;i<people;i++)
        cin>>time[i];
    
    for(int i=0;i<people;i++)
        time1[i]=time[i];
    
    int time_now=0;
    while(people1>0){
        time_now++;
        for(int i=serveend+1;i<=people;i++)
            total_time++;
        time1[serve1]--;
        if(time1[serve1]==0){serve1=serveend;serveend++;people1--;}
        time1[serve2]--;
        if(time1[serve2]==0){serve2=serveend;serveend++;people1--;}
        time1[serve3]--;
        if(time1[serve3]==0){serve3=serveend;serveend++;people1--;}
    }
    
    /*for(int i=0;i<people;i++){
        if(i%3==0)timea+=time[i];
        if(i%3==1)timeb+=time[i];
        if(i%3==2)timec+=time[i];
    }
    if(timea>=timeb){if(timea>=timec)result=timea;else result=timec;}
    if(timea<timeb){if(timeb>=timec)result=timeb;else result=timec;}
    int serve11=0,serve22=1,serve33=2;
    int all1=0,all2=0,all3=0;
    int timeaa=0,timebb=0,timecc=0;
    int tmp=people%3;
    if(tmp==0)all1=all2=all3=people/3;
    if(tmp==1){all1=(people-1)/3+1;all2=(people-1)/3;all3=(people-1)/3;}
    if(tmp==2){all1=(people-2)/3+1;all2=(people-2)/3+1;all3=(people-2)/3;}
    int alll1=all1;
    int alll2=all2;
    int alll3=all3;
    //cout<<alll1<<' '<<alll2<<' '<<alll3<<endl;
    while(all1>0){
        time2[serve11]--;
        for(int i=serve11/3+2;i<=alll1;i++){timeaa++;}
        if(time2[serve11]==0){serve11+=3;all1--;}
    }
    while(all2>0){
        time2[serve22]--;
        for(int i=(serve22-1)/3+2;i<=alll2;i++)timebb++;
        if(time2[serve22]==0){serve11+=3;all2--;}
    }
    while(all3>0){
        time2[serve33]--;
        for(int i=(serve33-2)/3+2;i<=alll3;i++)timecc++;
        if(time2[serve33]==0){serve11+=3;all3--;}
    }
    int final_time=timeaa+timebb+timecc;
    cout<<final_time<<' '<<result<<endl;
    */
    long long s[3]={0,0,0};
    long long sum[3]={0,0,0};
    for(int i=0;i<people;i+=3)
    {
        s[0]+=sum[0];
        sum[0]+=time[i];
    }
    for(int i=1;i<people;i+=3)
    {
        s[1]+=sum[1];
        sum[1]+=time[i];
        
    }
    for(int i=2;i<people;i+=3)
    {
        s[2]+=sum[2];
        sum[2]+=time[i];
        
    }
    long long final_time=s[0]+s[1]+s[2];
    long long result=max(sum[0],sum[1],sum[2]);

    cout<<final_time<<' '<<result<<endl;
    cout<<total_time<<' ' <<time_now<<endl;
    
    return 0;
}
