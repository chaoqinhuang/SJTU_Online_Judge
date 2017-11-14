//
//  main.cpp
//  1541
//
//  Created by 黄潮钦 on 2017/10/27.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include <cstdio>
#include <cstdlib>

using namespace std;

const int MAXN = 200020;
long int a[MAXN], qup[MAXN], qdw[MAXN], ans[MAXN];
int hup, tup, hdw, tdw;
int n, len;

int main()
{
    scanf("%d%d", &len,&n);
    for (int i = 1; i <= n; i++)
        scanf("%ld", &a[i]);;
    hup = 1; tup = 1; qup[1] = 1;
    hdw = 1; tdw = 1; qdw[1] = 1;//在qup（升序）的队首得窗中最小元素，在qdw（降序）的队首的窗中最大元素
    //if (len == 1) printf("%d ", a[1]);
    ans[1] = a[1];
    for (int i = 2; i <= n; i++)//遍历每个元素
    {
        while (a[i] <= a[qup[tup]] && tup >= hup) tup--;//队不为空且队尾的元素比新元素小的时候才插入新元素
        qup[++tup] = i;//队尾加入新元素序号i
        
        while (a[i] >= a[qdw[tdw]] && tdw >= hdw) tdw--;//队不为空且队尾的元素比新元素大的时候才插入新元素
        qdw[++tdw] = i;//队尾加入新元素序号i
        
        if (qup[hup] <= i - len) hup++;
        if (qdw[hdw] <= i - len) hdw++;//队首元素不在窗中的时候要做适当的调整
        //if (i >= len) printf("%d ", a[qup[hup]]);//此时窗中的最小值
        ans[i] = a[qdw[hdw]];//此时窗中的最大值
    }
    //printf("\n");
    for (int i = len; i <= n; i++)
        printf("%ld ", ans[i]);
    //printf("\n");
    return 0;
}
