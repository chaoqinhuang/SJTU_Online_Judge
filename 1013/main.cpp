//
//  main.cpp
//  1013
//
//  Created by 黄潮钦 on 2017/10/19.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_NUM = 1000 + 5;
const int MAX_CAPACITY = 10000 + 5;
const int INF = 100000000;

// 物品种类
int n;
// 背包容量
int C;
// 体积
int volumn[MAX_NUM];
// 重量
int weight[MAX_NUM];
// dp[i]表示体积为i时的最大重量
int dp[MAX_CAPACITY];

void solve() {
    dp[0] = 0;
    int ans = -INF;
    for(int i = 1; i <= C; i++) {
        dp[i] = -INF;
    }
    
    for(int i = 1; i <= C; i++) {
        for(int j = 1; j <= n; j++) {
            if(i >= volumn[j]) {
                dp[i] = max(dp[i], dp[i - volumn[j]] + weight[j]);
                if(dp[i] > ans) {
                    ans = dp[i];
                }
            }
        }
    }
    cout << ans;
}

int dpBag(int S) {
    int& ans = dp[S];
    if(ans >= 0) {
        return ans;
    }
    ans = 0;
    for(int i = 1; i <= n; i++) {
        if(S >= volumn[i]) {
            ans = max(ans, dpBag(S - volumn[i]) + weight[i]);
        }
    }
    return ans;
}

int main() {
    
        cin >> C;
    cin>>n;
        for(int i = 1; i <= n; i++) {
            cin >>  volumn[i]>>weight[i];
        }
        solve();
        
        //memset(dp, -1, sizeof(dp));
        //cout << dpBag(C) << endl;
    return 0;
}
