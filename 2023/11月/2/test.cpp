#include <iostream>
using namespace std;

// class Date
// {
// public:
//     Date(int year, int month, int day)
//     {
//         _year = year;
//         _month = month;
//         _day = day;
//     }

// private:
//     int _year;
//     int _month;
//     int _day;
// };

// class Date
// {
// public:
//     Date(int year, int month, int day)
//         : _year(year), _month(month), _day(day)
//     {
//     }

// private:
//     int _year;
//     int _month;
//     int _day;
// };

class A
{
public:
    A(int a)
        : _a1(a)
    {
        cout << "A(int a)" << endl;
    }

    A(const A &aa)
        : _a1(aa._a1)//拷贝构造也是构造，也可以进行初始化列表
    {
        cout << "A(const A& aa)" << endl;
    }

    // void Print()
    // {
    //     cout << _a1 << " " << _a2 << endl;
    // }

private:
    int _a2;
    int _a1;
};

int main()
{
    int i = 1;
    double d = i; // 隐式类型转换 i通过创建一个临时变量(具有常性，double类型)，i->临时变量->d

    A aa1(1);  // 直接调用 构造函数
    A aa2 = 1; // 隐式类型转换 1通过创建一个临时变量(具有常性，A类型)，i->临时变量->d

    return 0;
}