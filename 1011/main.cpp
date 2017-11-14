//
//  main.cpp
//  1011
//
//  Created by 黄潮钦 on 2017/8/10.
//  Copyright © 2017年 黄潮钦. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<iomanip>
using namespace std;

class Complex
{
public:
    void Display()
    {
        cout << "_real：" << _real << "      "<<"_image：" << _image << endl;
    }
public:
    //Complex()//无参数构造函数
    //{
    //  _real=_real;
    //  _image=_image;
    //}
    friend std::istream& operator>>(std::istream &,Complex &);         //友元输入操作符，需私有数据
    friend std::ostream& operator<<(std::ostream &,const Complex &);   //友元输出操作符，需私有数据
    Complex(double real = 1.0, double image = 2.0)//全缺省参数构造函数
    {
        //cout << "Complex(double real = 1.0, double image = 2.0)" << endl;
        _real = real;
        _image = image;
    }
    //Complex(const Complex& c)//拷贝构造函数。注意引用符，若为值传递则可能会引发无穷递归
    //{
    //  _real = c._real;
    //  _image = c._image;
    //}
    Complex(const Complex& c)////拷贝构造函数
    :_real(c._real)
    ,_image(c._image)
    {
        cout << "Complex(const Complex& c)" << endl;
    }
    ~Complex()//析构函数
    {
        //cout << "~Complex()"<< endl;
    }
public:
    Complex& operator=(const Complex& x)//赋值操作符的重载
    {
        if (this != &x)
        {
            this->_real = x._real;
            this->_image = x._image;
        }
        return *this;
    }
    bool operator==(const Complex& x)//比较两个复数是否相等
    {
        return this->_real == x._real && this->_image == x._image;
    }
    bool operator>(const Complex& x)//判断第一个复数大于第二个复数，分为多种情况
    {
        if (this->_real && x._real)
        {
            if (this->_real > x._real)
                return true;
            if (this->_real == x._real && this->_image > x._image)
                return true;
        }
        else if (this->_real)
            return true;
        else if (!this->_real || !x._real)
        {
            if (this->_image > x._image)
                return true;
        }
        else
            return false;
        return false;
    }
    bool operator<(const Complex& x)//判断第一个复数小于第二个复数，分为多种情况
    {
        if (this->_real && x._real)
        {
            if (this->_real < x._real)
                return true;
            if (this->_real == x._real && this->_image < x._image)
                return true;
        }
        else if (x._real)
            return true;
        else if (!this->_real || !x._real)
        {
            if (this->_image < x._image)
                return true;
        }
        else
            return false;
        return false;
    }
    Complex operator + (const Complex& x)//加法。+匿名对象不用&返回
    {
        Complex tmp;
        tmp._real = this->_real + x._real;
        tmp._image = this->_image + x._image;
        return tmp;
    }
    Complex& operator += (const Complex& x)//+=匿名对象用&返回this
    {
        this->_real += x._real;
        this->_image += x._image;
        return *this;
    }
    Complex operator - (const Complex& x)//减法
    {
        Complex tmp;
        tmp._real = this->_real - x._real;
        tmp._image = this->_image - x._image;
        return tmp;
    }
    Complex& operator -= (const Complex& x)
    {
        this->_real -= x._real;
        this->_image -= x._image;
        return *this;
    }
    Complex operator * (const Complex& x)//乘法
    {//复数乘法运算：(a + bi)*(c + di) = (ac - bd) + (ad + bc)i;
        Complex tmp;
        tmp._real = this->_real * x._real - this->_image * x._image;
        tmp._image = this->_real * x._image + this->_image * x._real;
        return tmp;
    }
    Complex& operator *= (const Complex& x)
    {
        *this = *this * x;
        return *this;
    }
    Complex operator / (const Complex& x)//除法
    {//复数除法运算：(a+bi)/(c+di) = x+yi, x =(ac+bd)/(c*c+d*d), y =(bc-ad)/(c*c+d*d);
        Complex tmp;
        tmp._real = (this->_real * x._real + this->_image * x._image)
        / (x._real*x._real + x._image*x._image);
        tmp._image = (this->_image * x._real - this->_real * x._image)
        / (x._real*x._real + x._image*x._image);
        return tmp;
    }
    Complex& operator /= (const Complex& x)
    {
        *this = *this / x;
        return *this;
    }
private:
    double _real;
    double _image;
};

inline std::istream& operator>>(std::istream &is,Complex &com)
{
    is >> com._real;
    if(is)
    {
        is >> com._image;
        if(is)
        {
            return is;
        }
        else
        {
            com = Complex(0.0);
        }
    }
    else
    {
        com = Complex(0.0);
    }
    return is;
}

inline std::ostream& operator<<(std::ostream &os, const Complex &com)
{
    os <<  setiosflags(ios::fixed)<<setprecision(2)<<com._real << " " << com._image;
    return os;
}

void Test()
{
    //构造函数
    //Complex p;
    //p.Display();
    Complex p1;
    Complex p2(2.0,1.0);
    p1.Display();
    p2.Display();
    //拷贝构造函数
    Complex p3(p1);
    Complex p4 = p1;
    p3.Display();
    p4.Display();
}

void Test1()
{//操作符的重载
    Complex p1(2.0, 3.0);
    Complex p2(2.0, 1.0);
    Complex p;
    p1.Display();
    p2.Display();
    p = p1;
    p.Display();
    bool ret;
    ret = p1 == p2;
    cout << "---------ret = " << ret << endl;
    ret = p1 > p2;
    cout << "---------ret = " << ret << endl;
    ret = p1 < p2;
    cout << "---------ret = " << ret << endl;
}

void Test2()
{//复数类的四则运算
    Complex p1(1.0, 2.0);
    Complex p2(2.0, 1.0);
    Complex p3(3.0, 5.0);
    Complex p4(2.0, 3.0);
    Complex p5(4.0, 8.0);
    p1.Display();
    //加法
    p2.Display();
    Complex add1 = p2 + p1;
    cout << "--------------------add1" << endl;
    add1.Display();
    p2 += p1;
    cout << "--------------------add2" << endl;
    p2.Display();
    cout << endl << endl;
    Complex sub1 = p3 - p1;
    //减法
    p3.Display();
    cout << "--------------------sub1" << endl;
    sub1.Display();
    p3 -= p1;
    cout << "--------------------sub2" << endl;
    p3.Display();
    cout << endl << endl;
    //乘法
    p4.Display();
    p4 *= p1;
    cout << "--------------------mul" << endl;
    p4.Display();
    cout << endl << endl;
    //除法
    p5.Display();
    p5 -= p2;
    cout << "--------------------div" << endl;
    p5.Display();
}

int main()
{
    //Test();
    //Test1();
    //Test2();
    //system("pause");
    Complex z1;
    Complex z2;
    cin >> z1;
    cin >> z2;
    
    cout << z1 + z2 <<endl;
    cout << z1 - z2 <<endl;
    cout << z1 * z2 <<endl;
    cout << z1 / z2 <<endl;
    cout << (z1 += z2) <<endl;
    cout << (z1 -= z2) <<endl;
    cout << (z1 *= z2) <<endl;
    cout << (z1 /= z2) <<endl;
    return 0;
}
