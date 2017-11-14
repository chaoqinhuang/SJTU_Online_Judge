//
//  main.cpp
//  1205
//
//  Created by 黄潮钦 on 2017/9/28.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include <iostream>
using namespace std;
int ack(int m,int n)
{
    if(m == 0)
        return n+1;
    else if(n == 0)
        return ack(m-1,1);
    else
        return ack(m-1,ack(m,n-1));
}

int main(int argc, const char * argv[]) {
    int a,b;
    cin>>a>>b;
    cout<<ack(a,b);
    return 0;
}
