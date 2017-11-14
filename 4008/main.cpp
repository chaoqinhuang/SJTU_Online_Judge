//
//  main.cpp
//  4008
//
//  Created by 黄潮钦 on 2017/10/12.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    int aa[101],bb[101],cc[101],jin=0;
    char a[101],b[101],c[101];
    cin>>a;
    cin>>b;
    int lena=strlen(a);
    int lenb=strlen(b);
    //cout<<lena<<endl;
    //cout<<lenb<<endl;
    int max=lena>lenb?lena:lenb;
    //cout<<max;
    int min=lena<=lenb?lena:lenb;
    for(int i=0;i<lena;i++){aa[i]=int(a[lena-i-1]-'a');}
    //for(int i=0;i<lena;i++)cout<<aa[i]<<' ';
    for(int i=0;i<lenb;i++){bb[i]=int(b[lenb-i-1]-'a');}
    for(int i=0;i<min;i++){
        cc[i]=(aa[i]+bb[i]+jin)%26;
        jin=(aa[i]+bb[i]+jin)/26;
    }
    if(lena>lenb){
        for(int i=lenb;i<max;i++){cc[i]=(aa[i]+jin)%26;jin=(aa[i]+jin)/26;}
    }
    else{
        for(int i=lena;i<max;i++){cc[i]=(bb[i]+jin)%26;jin=(bb[i]+jin)/26;}
    }
    if(jin==1)cout<<"b";
    for(int i=max-1;i>=0;i--)cout<<char(cc[i]+'a');
    
    return 0;
}
