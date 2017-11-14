#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e3+10;
char s1[N],s2[N];
int p,a1[N],a2[N],a3[N],a4[N];
inline bool bi(int a[],int b[]){
    if(a[0]<b[0]) return 0;
    if(a[0]>b[0]) return 1;
    for(int i=a[0];i;i--){
        if(a[i]<b[i]) return 0;
        if(a[i]>b[i]) return 1;
    }
    return 1;
}
inline void jian(int a[],int b[]){
    for(int i=1;i<=a[0];i++){
        if(a[i]<b[i]){
            a[i]+=10;
            a[i+1]--;
        }
        a[i]-=b[i];
    }
    for(;!a[a[0]]&&a[0]>1;a[0]--);
}
int main(){
    scanf("%s%s",s1,s2);
    int len1=strlen(s1);
    int len2=strlen(s2);
    for(int i=len1-1;i+1;i--) a1[++p]=s1[i]-'0';p=0;
    for(int i=len2-1;i+1;i--) a2[++p]=s2[i]-'0';p=0;
    a1[0]=len1;
    a2[0]=len2;
    a4[0]=len1-len2+1;
    for(int i=a4[0];i;i--){
        memset(a3,0,sizeof a3);
        for(int j=1;j<=a2[0];j++) a3[j+i-1]=a2[j];
        a3[0]=a2[0]+i-1;
        while(bi(a1,a3)) a4[i]++,jian(a1,a3);
    }
    for(;!a4[a4[0]]&&a4[0]>1;a4[0]--);
    for(int i=a4[0];i;i--) printf("%d",a4[i]);
    return 0;
}
