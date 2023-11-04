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
// A aa2 = 1;

// const A &ret = 10;

class A
{
public:
    explicit A(int a)
        : _a1(a)
    {
        cout << "A(int a)" << endl;
    }
    A(int a1, int a2)
        : _a1(a1), _a2(a2)
    {
    }

    A(const A &aa)
        : _a1(aa._a1)
    {
        cout << "A(const A& aa)" << endl;
    }

private:
    int _a2;
    int _a1;
};

int main()
{
    // 多参数构造函数
    A aa2(1, 1);
    A aa3 = {2, 2};

    return 0;
}