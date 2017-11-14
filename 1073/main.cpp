//
//  main.cpp
//  1073
//
//  Created by 黄潮钦 on 2017/10/19.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include<iostream>
#define N 201
using namespace std;
int main() {
    int n,e[N],maxa[N][N],ans=0;
    cin>>n;
    for(int a=1;a<=n;a++){
        cin>>e[a];
        e[a+n]=e[a];
    }
    //
    for(int i=2;i<2*n;i++){
        for(int j=i-1;j>0&&i-j<n;j--){
            for(int k=j;k<i;k++){
                int maxb;
                maxb=maxa[j][k]+maxa[k+1][i]+e[j]*e[k+1]*e[i+1];
                if(maxb>maxa[j][i]){
                    maxa[j][i]=maxb;
                }
            }
            if(maxa[j][i]>ans)
                ans=maxa[j][i];
        }
    }
    
    
    cout<<ans<<endl;
    return 0;
}
