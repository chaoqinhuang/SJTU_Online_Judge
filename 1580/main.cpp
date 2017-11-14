//
//  main.cpp
//  1580
//
//  Created by 黄潮钦 on 2017/10/27.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//
/*
#include <stdio.h>
void Longest_sub_seq(long int *a, long int n)
{
    if(n==0)
        return;  //empty sequence
    long int *S=new long int[n]();
    long int max_value=1;
    long int max_value_idx=0;
    S[0]=1;
    for(int i=1;i<n;i++)
    {
        long int curr_max_value=1;
        for(int r=0;r<i;r++)
        {
            if(a[r]<a[i] && S[r]+1>curr_max_value)
                curr_max_value=S[r]+1;
        }
        S[i]=curr_max_value;
        if(curr_max_value>max_value)
        {
            max_value=curr_max_value;
            max_value_idx=i;
        }
        
    }
    //print the max value and the longest sub sequence
    //int i=max_value_idx;
    printf("%ld",max_value);
    while(S[i]>1)
    {
        printf("%d->",a[i]);
        for(int r=0;r<i;r++)
        {
            if(S[r]+1==S[i] && a[r]<a[i])
            {
                i=r;
                break;
            }
        }
    }
    printf("%d",a[i]);
 
    
    delete [] S;
}
int main()
{
    long int a[1000001];
    long int n;
    scanf("%ld",&n);
    for(long int i=0;i<n;i++){
        scanf("%ld",&a[i]);
    }
    Longest_sub_seq(a,n);
    return 0;
}
*/

/************************************************************************/
/* 算法导论15.4-6
 * 找出n个数的序列中最长的单调递增子序列
 * 时间复杂度为O(nlgn)*/
/************************************************************************/
#include<iostream>
#include<vector>
using namespace std;
void printSequence(int *b,int* nums,int last);
int main()
{
    long int n;
    cin>>n;
    
    
    long int nums[1000001];
    for(long int i=0;i<n;i++)cin>>nums[i];
    //数组b存储在递增子序列中当前元素的前一个元素序号
    
    int *b=new int[n];
    //vector容器last中存储各不同长度的递增子序列(同一长度的子序列，只考虑尾元素最小的序列)
    // 中最后一个元素的序号
    vector<int> last;
    last.push_back(0);
    b[0]=0;
    for (int i=1;i<n;i++)
    {
        long int low=0,high=last.size()-1;
        long int middle=(low+high)/2;
        long int pos;
        if(nums[i]>nums[last[high]])
        {//如果当前元素比last中所有元素都大则最长递增子序列的长度加一，其尾元素为当前元素nums[i]
            last.push_back(i);
            b[i]=last[high];
        }else{//否则使用二分法在last中查找到大于等于当前元素nums[i]的最小元素
            while(low<high)
            {
                middle=(high+low)/2;
                
                if(nums[i]>nums[last[middle]])
                    low=middle+1;
                else
                    high=middle-1;
            }
            //更新last中的元素值
            if(nums[i]>nums[last[low]])
                pos=low+1;
            else
                pos=low;
            last[pos]=i;
            b[i]=last[pos-1<0 ? 0 : pos-1];
        }
    }
    
    //cout<<"原序列长度为"<<n<<"，如下："<<endl;
    //for (int i=0;i<n;i++)
    //{
    //    cout<<nums[i]<<" ";
    //}
    long int len=last.size();
    cout<<len;
    //printSequence(b,nums,last[len-1]);
    //cout<<endl;
    delete[] b;
    return 0;
}

void printSequence(int *b,int* nums,int last)
{
    if(b[last]!=last)
        printSequence(b,nums,b[last]);
    cout<<nums[last]<<" ";
}
