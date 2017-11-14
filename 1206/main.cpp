//
//  main.cpp
//  1206
//
//  Created by 黄潮钦 on 2017/9/28.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#include<iostream>
#include <string.h>
using namespace std;

template <typename T>
class Stack
{
public:
    Stack()
    {
        _raw = new T[20];
        _size = 0;
        _capacity = 20;
    }
    
    Stack(int cap)
    {
        _raw = new T[cap];
        _size = 0;
        _capacity = cap;
    }
    
    ~Stack() {
        delete[] _raw;
    }
    
    void push(const T &val)
    {
        _try_expand();
        _raw[_size] = val;
        _size += 1;
    }
    
    T pop() {
        _size -= 1;
        return _raw[_size];
    }
    
    T& peek() {
        return _raw[_size - 1];
    }
    
    int size() const
    {
        return _size;
    }
    
    Stack<T> clone()
    {
        Stack<T> n(_size);
        
        for (int i = 0; i < _size; ++i)
        {
            n[i] = _raw[i];
        }
        n._size = _size;
        
        return n;
    }
    
private:
    int _size;
    int _capacity;
    T *_raw;
    
    void _try_expand()
    {
        if (_size < _capacity)
        {
            return;
        }
        
        _expand_to(_capacity << 1);
    }
    
    void _expand_to(int cap)
    {
        T *alloc = new T[cap];
        for (int i = 0; i < _size; ++i)
        {
            alloc[i] = _raw[i];
        }
        
        delete[] _raw;
        _raw = alloc;
        _capacity = cap;
    }
};


enum Token {
    Begin, End, If, Then, Else, EndMarker, ExpectElse
};

class Tokenizer {
public:
    Token next() {
        while (true) {
            if (std::cin.eof()) {
                return EndMarker;
            }
            
            std::string input;
            std::cin >> input;
            
            if (input == "begin") {
                return Begin;
            }
            if (input == "end") {
                return End;
            }
            if (input == "if") {
                return If;
            }
            if (input == "then") {
                return Then;
            }
            if (input == "else") {
                return Else;
            }
        }
    }
};

bool check_match() {
    Stack<Token> states;
    Tokenizer tokenizer;
    
    Token current = tokenizer.next();
    if (current == EndMarker) {
        return true;
    }
    
    states.push(current);
    current = tokenizer.next();
    while (current != EndMarker) {
        switch (states.peek())
        {
            case Begin:
                if (current == Begin || current == If) {
                    states.push(current);
                }
                else if (current == End) {
                    states.pop();
                }
                else if (current == Then || current == Else) {
                    return false;
                }
                current = tokenizer.next();
                break;
            case If:
                if (current == Then) {
                    states.pop();
                    states.push(ExpectElse);
                }
                else {
                    return false;
                }
                current = tokenizer.next();
                break;
            case ExpectElse:
                if (current == Begin || current == If) {
                    states.push(current);
                    current = tokenizer.next();
                }
                else if (current == Else){
                    states.pop();
                    current = tokenizer.next();
                }
                else if (current == End) {
                    states.pop();
                }
                else if (current == Then) {
                    return false;
                }
                break;
            default:
                break;
        }
    }
    
    while (states.peek() == ExpectElse) {
        states.pop();
    }
    
    return states.size() == 0;
}

int main() {
    if (check_match()) {
        std::cout << "Match!" << std::endl;
    }
    else {
        std::cout << "Error!" << std::endl;
    }
    
    return 0;
}
