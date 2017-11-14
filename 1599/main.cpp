//
//  main.cpp
//  1599
//
//  Created by 黄潮钦 on 2017/10/12.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//
/*
#include <stdio.h>

class Stack {
public:
    Stack(int cap) {
        _storage = new char[cap];
        _size = 0;
        _is_dirty = true;
    }
    
    ~Stack() {
        delete[] _storage;
    }
    
    void push(char c) {
        _storage[_size++] = c;
        _is_dirty = true;
    }
    
    void pop() {
        _size -= 1;
        _is_dirty = true;
    }
    
    char top() {
        return _storage[_size - 1];
    }
    
    bool empty() {
        return _size == 0;
    }
    
    bool is_matched() {
        if (!_is_dirty) {
            return _is_matched;
        }
        
        _is_matched = _matched_helper();
        _is_dirty = false;
        return _is_matched;
    }
    
    char& operator[](int index) {
        return _storage[index];
    }
private:
    bool _matched_helper() {
        char* stack = new char[_size];
        int stack_ptr = 0;
        
        bool keep_going = true;
        bool matched = true;
        for (int i = 0; i < _size && keep_going; ++i) {
            switch (_storage[i])
            {
                case '(':
                    stack[stack_ptr++] = '(';
                    break;
                case '[':
                    stack[stack_ptr++] = '[';
                    break;
                case '{':
                    stack[stack_ptr++] = '{';
                    break;
                case ')':
                    if (stack_ptr == 0 || stack[stack_ptr - 1] != '(') {
                        matched = false;
                        keep_going = false;
                    }
                    else {
                        stack_ptr -= 1;
                    }
                    break;
                case ']':
                    if (stack_ptr == 0 || stack[stack_ptr - 1] != '[') {
                        matched = false;
                        keep_going = false;
                    }
                    else {
                        stack_ptr -= 1;
                    }
                    break;
                case '}':
                    if (stack_ptr == 0 || stack[stack_ptr - 1] != '{') {
                        matched = false;
                        keep_going = false;
                    }
                    else {
                        stack_ptr -= 1;
                    }
                    break;
            }
        }
        
        return matched && (stack_ptr == 0) ? true : false;
    }
    
    char* _storage;
    int _size;
    bool _is_dirty;
    bool _is_matched;
    
};

int main() {
    int op_num;
    scanf("%d\n", &op_num);
    Stack stack(op_num);
    
    for (int i = 0; i < op_num; ++i) {
        int op_id;
        scanf("%d", &op_id);
        
        if (op_id == 1) {
            char c;
            scanf(" %c\n", &c);
            stack.push(c);
        }
        else if (op_id == 2) {
            if (!stack.empty()) {
                stack.pop();
            }
        }
        else if (op_id == 3) {
            if (!stack.empty()) {
                char c = stack.top();
                printf("%c\n", c);
            }
        }
        else if (op_id == 4) {
            if (stack.is_matched()) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
        }
    }
    
    return 0;
}
*/


#include <stdio.h>
char k[1000001];
int ii=0,start=0,last_s=0,las_s=0,tmp=0,change=1,last=0;
int check()
{
    char s[ii];
    int top=-1;
    int len=ii;
    for(int i=0;i<len;i++)
    {
        if(k[i]=='['||k[i]=='('||k[i]=='{')
        {
            s[++top]=k[i];
        }
        else{
            if((k[i]-s[top])==1||(k[i]-s[top])==2)
                top--;
            else{
                s[++top]=k[i];
            }
        }
    }
    if(top==-1)        {printf("YES\n");
        change=0;last=1;
    }
    else   {printf("NO\n");change=0;last=0;
    }
    return 0;
}

int main(){
    int hh;
    long long int n;
    scanf("%lld",&n);
    while(n--){
        scanf("%d",&hh);
        if(hh==1){scanf("%1s",&k[ii]);ii++;change=1;}
        else if(hh==2){if(ii>=1)ii--;change=1;}
        else if(hh==3){if(ii>=1){printf("%.1s",&k[ii-1]);printf("\n");}}
        else if(hh==4){if(change==0)
        {if(last==1)printf("YES\n");
        else printf("NO\n");
        }
        else check();
        }
    }
    return 0;
}

/*
#include <iostream>
#include<string.h>
using namespace std;
struct node
{
    char ch;
    node *next;
} *head;
node* instack(char c)//某个元素入栈
{
    node *p;
    static int count1=0;
    if(count1==0)
    {
        p=new node;
        p->ch=c;
        p->next=NULL;
        count1++;
        return p;
    }
    else
    {
        p=new node;
        p->ch=c;
        p->next=head;
        return p;
    }
}
void stack_pop()//栈顶的元素出栈
{
    node *p;
    // char c;
    // c=head->ch;
    p=head;
    head=head->next;
    delete p;
    //return c;
}
char stack_top()//取出栈顶元素
{
    return head->ch;
}
bool stack_empty()//判断栈是否为空
{
    if(head==NULL)
        return true;
    return false;
}
int main()
{
    int i,k;
    char s[101],c;
    bool YON=true;
    while(cin>>s)
    {
        k=strlen(s);
        for(i=0; i<k; i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')//出现左括号则入栈
            {
                head=instack(s[i]);
            }
            if(s[i]==')'||s[i]==']'||s[i]=='}')//出现右括号
            {
                if(!stack_empty())//判断是否为空
                {
                    c=stack_top();//取出栈顶元素
                    if(!((s[i]==']'&&c=='[')||(s[i]=='}'&&c=='{')||(s[i]==')'&&c=='(')))//判断是否匹配
                    {
                        YON=false;
                        break;
                    }
                    else stack_pop();//匹配则栈顶元素出栈
                }
                else
                {
                    YON=false;
                    break;
                }
            }
        }
        if(YON)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        memset(s,'\0',sizeof(s));
    }
    return 0;
}
*/
