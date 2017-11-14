//
//  main.cpp
//  1049
//
//  Created by 黄潮钦 on 2017/9/28.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include <iostream>//写的C++代码
#include <stack>//调用堆栈
#include <vector>
using namespace std;//使用标准命名空间
int res[301];
void load_outgoing(int number, vector<int>& stack) {
    for (int i = 0; i < number; ++i) {
        int n;
        std::cin >> n;
        stack.push_back(n);
    }
}

void load_incoming(int number, stack<int>& stack) {
    for (int i = number - 1; i >= 0; --i) {
        stack.push(i);
    }
}

int main()
{
    int T=0;
    cin>>T;
    //int res[301];
    for(int i=0;i<301;i++){res[i]=1;}
    for(int jj=0;jj<T;jj++){
        int n,target[1001],c=1;//定义数组
        
        cin>>n>>c;
        //int now=0;
        vector<int> outgoing_stack;
        load_outgoing(n,outgoing_stack);
        stack<int> incoming_stack, station_stack;
        load_incoming(n, incoming_stack);
        
        //int A=0,B=0;//A是起始1....n火车入站的起始位置，B是坐标
        //stack<int> s;//定义一个堆栈
        int stack_ptr = 0;
        while (stack_ptr < n) {
            if (!station_stack.empty() && station_stack.top() == outgoing_stack[stack_ptr]) {
                stack_ptr += 1;
                station_stack.pop();
            }
            else if (incoming_stack.empty()) {
                res[jj]=0;break;
            }
            else if (incoming_stack.top() == outgoing_stack[stack_ptr]) {
                stack_ptr += 1;
                incoming_stack.pop();
            }
            else {
                if (station_stack.size() == c) {
                    res[jj]=0;break;
                }
                int train = incoming_stack.top();
                incoming_stack.pop();
                station_stack.push(train);
            }
        }
        //res[jj]=1;
        //if(ok)//开始输出，如果可能B收到所有火车，这时火车可能以这种方式出站，否则不可能，一下是可能的输出结果截图
            
            //res[jj]=1;else res[jj]=0;
    }
    for(int i=0;i<T;i++){if(res[i]==1)cout<<"YES"<<endl;else cout<<"NO"<<endl;}
    return 0;
}

/*
#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::stack;

void load_outgoing(int number, vector<int>& stack) {
    for (int i = 0; i < number; ++i) {
        int n;
        std::cin >> n;
        stack.push_back(n);
    }
}

void load_incoming(int number, stack<int>& stack) {
    for (int i = number - 1; i >= 0; --i) {
        stack.push(i);
    }
}

bool test_session() {
    int train_number, station_size;
    std::cin >> train_number >> station_size;
    vector<int> outgoing_stack;
    load_outgoing(train_number, outgoing_stack);
    stack<int> incoming_stack, station_stack;
    load_incoming(train_number, incoming_stack);
    
    int stack_ptr = 0;
    while (stack_ptr < train_number) {
        if (!station_stack.empty() && station_stack.top() == outgoing_stack[stack_ptr]) {
            stack_ptr += 1;
            station_stack.pop();
        }
        else if (incoming_stack.empty()) {
            return false;
        }
        else if (incoming_stack.top() == outgoing_stack[stack_ptr]) {
            stack_ptr += 1;
            incoming_stack.pop();
        }
        else {
            if (station_stack.size() == station_size) {
                return false;
            }
            int train = incoming_stack.top();
            incoming_stack.pop();
            station_stack.push(train);
        }
    }
    return true;
}

int main() {
    int session_num;
    std::cin >> session_num;
    for (int i = 0; i < session_num; ++i) {
        if (test_session()) {
            std::cout << "YES\n";
        }
        else {
            std::cout << "NO\n";
        }
    }
    
    return 0;
}
 */
