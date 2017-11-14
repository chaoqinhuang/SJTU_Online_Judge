//
//  main.cpp
//  1533
//
//  Created by 黄潮钦 on 2017/10/12.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin>>n;
    int a=1,b=1,resa,resb,ans=0,pp=0;
    cin>>resa>>resb;
    if(n==1){cout<<"0";return 0;}
    if(n==2){
        if(resa==1&&resb==1){cout<<"0";return 0;}
        if(resa==1&&resb==2){cout<<"1";return 0;}
        if(resa==2&&resb==2){cout<<"2";return 0;}
        if(resa==2&&resb==1){cout<<"3";return 0;}
    }
    if(n==3){
        if(resa==1&&resb==1){cout<<"0";return 0;}
        if(resa==1&&resb==2){cout<<"1";return 0;}
        if(resa==1&&resb==3){cout<<"2";return 0;}
        if(resa==2&&resb==3){cout<<"3";return 0;}
        if(resa==3&&resb==3){cout<<"4";return 0;}
        if(resa==3&&resb==2){cout<<"5";return 0;}
        if(resa==3&&resb==1){cout<<"6";return 0;}
        if(resa==2&&resb==1){cout<<"7";return 0;}
        if(resa==2&&resb==2){cout<<"8";return 0;}
    }
    while(true){
        while(b<n-pp){if(a==resa&&b==resb){cout<<ans;return 0;}b++;ans++;}
        while(a<n-pp){if(a==resa&&b==resb){cout<<ans;return 0;}a++;ans++;}
        while(b>pp+1){if(a==resa&&b==resb){cout<<ans;return 0;}b--;ans++;}
        while(a>pp+2){if(a==resa&&b==resb){cout<<ans;return 0;}a--;ans++;}
        pp++;
    }
    return 0;
}
