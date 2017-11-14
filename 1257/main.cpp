//
//  main.cpp
//  1257
//
//  Created by 黄潮钦 on 2017/10/19.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

struct node{
    int data;
    node *f;
    node *l;
    node *r;
    node() :f(NULL), l(NULL), r(NULL){}
    node(int d, node *pa = NULL, node *left = NULL, node *right = NULL)
    :data(d), f(pa), l(left), r(right){}
    //node(const node& n) :data(n.data), f(n.f), l(n.l), r(n.r){}
};

node root(1);
node *r[211111]{ NULL };    //这种写法在OJ时可以通过的;

node* getNode(int a, int b, int c){
    if (r[b] || r[c]) return NULL;
    else return r[a];
}

node* getNode(int d){
    return r[d];
}

void insert(int a, int b, int c){
    node *t = getNode(a, b, c);
    if (!t || b == c){    //没有a或者b==c或者找到b或者找到c
        printf("Error!\n"); return;
    }
    else{
        if (!t->l&&!t->r){
            if (b != 0){
                t->l = new node(b, t);
                r[b] = t->l;
            }
            if (c != 0){
                t->r = new node(c, t);
                r[c] = t->r;
            }
            printf("Ok!\n");
        }
        else printf("Error!\n");
    }
}

void find(int a){
    node *t = getNode(a);
    if (!t) printf("Error!\n");
    else{
        int pa = (t->f ? t->f->data : 0);
        int le = (t->l ? t->l->data : 0);
        int ri = (t->r ? t->r->data : 0);
        printf("%d %d %d\n", pa, le, ri);
    }
}

void exchange(int a){
    if (a == 1){
        printf("Error!\n");
        return;
    }
    
    node *t = getNode(a);
    if (!t) printf("Error!\n");
    else{
        if (t->f->l&&t->f->l->data == t->data){
            int sibling = (t->f->r ? t->f->r->data : 0);
            printf("%d\n", sibling);
            
            //node *tmp = t;    //Ok? No!这样tmp指向的内容会跟着一起变化！
            node *tmp = t;
            t->f->l = t->f->r;
            t->f->r = tmp;
        }
        else{
            int sibling = (t->f->l ? t->f->l->data : 0);
            printf("%d\n", sibling);
            
            node *tmp = t;
            t->f->r = t->f->l;
            t->f->l = tmp;
        }
    }
}

void preOrder(node *t){
    if (!t) return;
    printf("%d ", t->data);
    preOrder(t->l);
    preOrder(t->r);
}

int main(){
    r[1] = &root;
    int m;
    scanf("%d",&m);
    for (int i = 0; i < m; i++){
        int op; scanf("%d", &op);
        switch (op)
        {
            case(1) :
                int a, b, c;
                scanf("%d%d%d", &a, &b, &c);
                insert(a, b, c);
                break;
            case(2) :
                int d; scanf("%d", &d);
                find(d);
                break;
            case(3) :
                int x; scanf("%d", &x);
                exchange(x);
                break;
            default:
                break;
        }
    }
    preOrder(&root);
    printf("\n");
    return 0;
}

