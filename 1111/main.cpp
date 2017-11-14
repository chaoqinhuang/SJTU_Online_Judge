//
//  main.cpp
//  1111
//
//  Created by 黄潮钦 on 2017/10/12.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//
/*
#include <iostream>
#include <cstring>
#define MAX 50+3
using namespace std;
char ans[10000];
int cnt=0;
typedef char Elem_Type;
typedef struct BiTree
{
    Elem_Type data;//数据
    struct BiTree *Lchild;//左孩子
    struct BiTree *Rchild;//右孩子
    bool is_value;
}BiTree;      //要查找的元素  查找的地方    数组的长度
int Search_Num(Elem_Type num,Elem_Type *array,int len)
{
    for(int i=0; i<len; i++)
        if(array[i] == num)
            return i;
    return -1;//没有找到
}                     //前序遍历         中序遍历   中序数组长度
BiTree *Resume_BiTree(Elem_Type *front,Elem_Type *center,int len)
{
    if(len <= 0)
        return NULL;
    BiTree *temp = new BiTree;
    temp->data = *front;
    int index = Search_Num(*front,center,len);
    temp->Lchild = Resume_BiTree(front+1,center,index);
    temp->Rchild = Resume_BiTree(front+index+1,center+index+1,len-index-1);
    return temp;
}
void PostOrderTraverse(BiTree *root)//后序遍历
{
    if( root != NULL)
    {
        PostOrderTraverse(root->Lchild);
        PostOrderTraverse(root->Rchild);
        cout<<root->data;
    }
}

bool bfs(BiTree *root){
    BiTree *q[10000],*u;
    q[0] = root;
    int front = 0, rear = 1;
    while(front < rear){
        u = q[front++];
        if(u==NULL) {ans[cnt++] = '[';continue;};  //没有被赋过值，表明输入有误
        ans[cnt++] = u->data;                //增加到输出序列的尾部
        //if(u->Lchild != NULL) q[rear++] = u->Lchild; //把左儿子放入队列
        //else q[rear++]
        //if(u->Rchild != NULL) q[rear++] = u->Rchild;//把右儿子放入队列
        q[rear++] = u->Lchild;
        q[rear++] = u->Rchild;
    }
    return true;        //输入正确
}
int main(){
    Elem_Type *preorder = new Elem_Type [MAX];//前序
    Elem_Type *inorder  = new Elem_Type [MAX];//中序
    cin>>preorder;cin>>inorder;
    BiTree *root = Resume_BiTree(preorder,inorder,strlen(inorder));
    bfs(root);
            for(int i = 0; i < cnt; i++){   //按照层次遍历输出二叉树
                if(i) printf(" ");
                if(ans[i]=='[')cout<<"NULL";
                else cout<<ans[i];
            }
            printf("\n");
    return 0;
}
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXSIZE 1000
bool fun(char *Pre, char *Indor, char *Seq, int n, int R){
    int i, root;
    if(n <= 0)
        return 1;
    for(root = 0; (root < n) && (Indor[root] != Pre[0]); root++);
    if(root >= n)
        return 0;
    Seq[R] = Pre[0];
    for(i = 0; i < R; i++)
        if(Seq[i] == 0)
            Seq[i] = '0';
    bool b1 = fun(Pre + 1, Indor, Seq, root, 2 * R + 1);
    bool b2 = fun(Pre + 1 + root, Indor + root + 1, Seq, n - root - 1, 2 * R + 2);
    return b1 && b2;
    
}

int main(void){
    char Pre[26], Indor[26], Seq[1000], n;
    int i=0;
    bool bCreatOk;
    //printf("请输入前序序列:\n");
    scanf("%s", Pre);
    //printf("请输入中序序列:\n");
    scanf("%s", Indor);
    
    n = strlen(Pre);
    //cout<<"aa"<<endl;
    for(i = 0; i < 1000; i++)
        Seq[i] = 0;
    //cout<<"aa"<<endl;
    bCreatOk = fun(Pre,Indor, Seq, n, 0);
    
    if(bCreatOk) {
        //printf("构造二叉树成功!其顺序二叉树为:\n");
        for(i = 0; i<1000; i++)
            if(Seq[i]=='0')cout<<"NULL"<<' ';
            else if(Seq[i]>='A'&&Seq[i]<='Z')cout<<Seq[i]<<' ';
    }
    //else printf("不是一棵有效的二叉树!");
    printf("\n");
    return 0;
}
