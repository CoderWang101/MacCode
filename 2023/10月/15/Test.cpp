// #include "Test.h"

// int main()
// {
//     Func();
//     Func(100,20);
//     //Func(, ,30);错误用法，缺省函数只能从头进行更改，不能更改其中某一位置的值

//     return 0;
// }
// #include <iostream>
// using namespace std;

// void Func(int a = 10, int b = 20, int c = 30);

#include<iostream>
using namespace std;

// 1、参数类型不同
int Add(int left, int right) 
{
    cout << "int Add(int left, int right)" << endl;
    return left + right;
}

double Add(double left, double right)
{
    cout << "double Add(double left, double right)" << endl;
    return left + right;
}

// 2、参数个数不同 
void f()
{
    cout << "f()" << endl;
}
void f(int a)
{
    cout << "f(int a)" << endl;
}

int main()
{
    f(); 
    f(10);

    return 0;
}

// 3、参数类型顺序不同 
void f(int a, char b) 
{
    cout << "f(int a,char b)" << endl;
}

void f(char b, int a)
{
    cout << "f(char b, int a)" << endl;
}

int main()
{
    f(10, 'a');
    f('a', 10);

    return 0;
}
// int main()
// {
//     int a=1,b=2;
//     double c=1.1,d=1.1;

//     Add(a,b);
//     Add(c,d);

//     return 0;
// }