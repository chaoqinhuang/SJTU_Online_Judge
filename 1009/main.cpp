//
//  main.cpp
//  1009
//
//  Created by 黄潮钦 on 2017/8/10.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int m,n;
    double mon1,mon2,mon3,result=0;
    long int mt[50],ma[50],mm[50];
    long int nt[10001],na[10001];
    cin>>m;
    for(int i=0;i<m;i++)cin>>mt[i]>>ma[i]>>mm[i];
    cin>>n;
    for(int i=0;i<n;i++)cin>>nt[i]>>na[i];
    for(int i=0;i<m;i++)
    {
        //cout<<"in"<<endl;
        long int mon,pp=0;
        while(1)
        {
            if(mt[i]<nt[pp]){mon=na[pp-1];break;}
            if(pp==n-1){mon=na[pp];break;}
            pp++;
        }
        //for(int j=0;pp==0;j++)
        //    if(mt[i]>=nt[j]){time=j;pp=1;}
        //mon=na[time];
        pp=0;
        //cout<<mon<<endl;
        mon1=ma[i]*100*mon;
        mon2=mon1*0.002;
        if(mon2<5)mon2=5;
        cout<<mon2<<endl;
        if((ma[i]*100)%1000==0)mon3=ma[i]/10;
        else mon3=ma[i]/10;
        mon2+=mon3;
        mon2+=1;
        mon3=mon1*0.001;
        if(mm[i]==1)result=result-mon1-mon2;
        else result=result+mon1-mon2-mon3;
    }
    cout<<setiosflags(ios::fixed);
    cout.precision(2);
    cout<<result<<endl;
    return 0;
}
