//
//  main.cpp
//  1020
//
//  Created by 黄潮钦 on 2017/9/28.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int n,i,pp=0,last,num=1;
    int array[1000000];
    scanf("%d",&n);
    cout<<n<<"=";
    for(i=2;i<=n;i++)
    {while(n!=i)
               {
            if(n%i==0)
            { array[pp]=i;pp++;
                n=n/i;
            }
            else
            break;
        }
        }

        array[pp]=n;
    //for(int k=0;k<=pp;k++)cout<<array[k]<<" ";
    //cout<<endl;
    array[++pp]=0;
    for(int m=0;m<=pp;m++){
        if(m==0)last=array[m];
        else{
            if(array[m]==last){num++;}
            else{cout<<last<<"("<<num<<")";
                last=array[m];
                num=1;
            }
        }
    }
return 0;
}
