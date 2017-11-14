//
//  main.cpp
//  4009
//
//  Created by 黄潮钦 on 2017/9/28.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int l=0;
    char ming[101],mi[101],ans[101];
    cin>>ming;
    cin>>mi;
    //for(int i=0;i<101;i++)
    //{if(ming[i]>='A'&&ming[i]<='Z'||ming[i]>='a'&&ming[i]<='z')l++;
    //else break;
    //}
    l=strlen(ming);
    int a=2;
    for(a=2;a<l;++a)
        if(l%a==0){
            int k=0;
            for(int pp=0;pp<a;pp++){
                for(int j=pp;j<l;j+=a){
                    ans[k]=ming[j];
                    k++;
                }
            }
            if(strncmp(ans,mi,l)==0){cout<<a;break;}
        }
    
    return 0;
}
