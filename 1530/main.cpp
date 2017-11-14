//
//  main.cpp
//  1530
//
//  Created by 黄潮钦 on 2017/10/13.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
char one[20];
char two[20];
char s[1000010];
char t[1000010];
const char s1[10]="DECODE";
const char s2[10]="ENCODE";
const char s3[10]="PREORDER";
const char s4[10]="INORDER";
const char s5[10]="POSTORDER";
int strlen(char * p)
{
    int i=0;
    while(p[i]!='\0')i++;
    return i;
}
bool strcmp(char * p, char * q)
{
    if (strlen(p)!=strlen(q))return false;
    else
        for (int i=0;i<strlen(p);i++)
            if (p[i]!=q[i])return false;
    
    return true;
}
void output(int &sss){
    for (int i=0;i<sss;i++)cout<<t[i];
    
}
void inbuild(int &n,int p,int &sss)
{
    if (p>=sss)return;
    inbuild(n,2*p+1,sss);
    t[p]=s[n++];
    inbuild(n,2*p+2,sss);
}
void prebuild(int &n,int p,int& sss)
{
    if (p>=sss)return;
    t[p]=s[n++];
    prebuild(n,2*p+1,sss);
    prebuild(n,2*p+2,sss);
}
void pobuild(int & n,int p,int &sss)
{
    if (p>=sss)return;
    pobuild(n,2*p+1,sss);
    pobuild(n,2*p+2,sss);
    t[p]=s[n++];
}
void enin(int x,int& sss){
    if(x>=sss)return;
    enin(2*x+1,sss);
    cout<<s[x];
    enin(2*x+2,sss);
}
void enpre(int x,int & sss){
    if (x>=sss)return;
    cout<<s[x];
    enpre(2*x+1,sss);
    enpre(2*x+2,sss);
}
void enpost(int x,int &sss){
    if (x>=sss)return;
    enpost(2*x+1,sss);
    enpost(2*x+2,sss);
    cout<<s[x];
}
void depre(int &sss){
    int num=0;
    int pos=0;
    prebuild(num,pos,sss);
    output(sss);
}

void dein(int & sss){
    //int len=strlen(s);
    int num=0;
    int pos=0;
    inbuild(num,pos,sss);
    output(sss);
}
void depo(int & sss){
    //int len=strlen(s);
    int num=0;
    int pos=0;
    pobuild(num,pos,sss);
    output(sss);
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    int leng;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>leng;
        cin>>one>>two;
        cin>>s;
        if (two[0]=='D')
        {
            //cout<<"!!!"<<endl;
            if (one[1]=='N')
            {
                dein(leng);
                cout<<endl;
            }
            else if (one[1]=='R')
            {
                depre(leng);
                cout<<endl;
            }
            else if (one[1]=='O'){
                depo(leng);
                cout<<endl;
            }
        }
        else if (two[0]=='E')
        {
            //cout<<"!!!/!"<<endl;
            if (one[1]=='N'){
                enin(0,leng);
                cout<<endl;
                //cout<<"###"<<endl;
            }
            else if (one[1]=='R'){
                enpre(0,leng);
                cout<<endl;
                //cout<<"***"<<endl;
            }
            else if (one[1]=='O'){
                enpost(0,leng);
                cout<<endl;
                //cout<<"%%%"<<endl;
            }
        }
    }
    //system("pause");
    return 0;
}
