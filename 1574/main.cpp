//
//  main.cpp
//  1574
//
//  Created by 黄潮钦 on 2017/9/29.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
long long n,m,k,x,sum;
long long quite(void){                //快速幂运算
    long long a=1,b=10;
    while(k!=0){
        if(k&1)
            a=(a*b)%n;
        b=(b*b)%n;
        k>>=1;
    }
    return a;
}
int main(){
    long long i;
    scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
    i=quite();
    if(i==1){                      //余一的时候就不要加了
        printf("%lld",x);
    }
    else{
        sum=(x+m*i)%n;               //运行m*10^k次取n的余，10^k次取余用快速幂
        printf("%lld",sum);
    }
    return 0;
}
