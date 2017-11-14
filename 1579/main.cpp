//
//  main.cpp
//  1579
//
//  Created by 黄潮钦 on 2017/10/27.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    string str1,str2;
    int dp[1001][1001];
    
        int la;
        int lb;
        cin>>la>>lb;
        cin>>str1>>str2;
        memset(dp,0,sizeof(dp));
        
        
        
        for(int i = 1; i <= la; i++)
            for(int j = 1; j <= lb; j++)
            {
                if(str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        cout<<dp[la][lb]<<endl;
    
    return 0;
}
