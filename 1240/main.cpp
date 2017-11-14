//
//  main.cpp
//  1240
//
//  Created by 黄潮钦 on 2017/9/27.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int month,all=1,now=1,can[10000];
    for(int i=0;i<10000;i++) can[i]=0;
    cin>>month;
    while(--month>=0){
        for(int i=0;i<all;i++){can[i]++;if(can[i]>=2)now++;
    }
        all=now;
    }
        cout<<all;
    return 0;
}
