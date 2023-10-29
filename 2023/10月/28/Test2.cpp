#include <iostream>
using namespace std;

class Date
{
public:
    // 构造函数
    Date(int year = 1, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    // 拷贝构造
    Date(const Date &d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }

    void Print()
    {
        cout << _year << "/" << _month << "/" << _day << endl;
    }

    // bool operator<(const Date &d)
    // {
    //     if (_year < d._year)
    //     {
    //         return true;
    //     }
    //     else if (_year == d._year && _month < d._month)
    //     {
    //         return true;
    //     }
    //     else if (_year == d._year && _month == d._month && _day < d._day)
    //     {
    //         return true;
    //     }
    //     else
    //         return false;
    // }

    // d1==d2 -> d1.operator==(d2)
    bool operator==(const Date &d)
    {
        return _year == d._year && _month == d._month && _day == d._day;
        //    this->_year==d.year
    }

    // d1<d2
    bool operator<(const Date &d)
    {
        return _year < d._year && (_year == d._year && _month < d._month) && (_year == d._year && _month == d._month && _day < d._day);
    }

    // d1<=d2
    bool operator<=(const Date &d)
    {
        return *this < d || *this == d; //*this就是d1
    }

    // d1>d2
    bool operator>(const Date &d)
    {
        return !(*this <= d);
    }

    // d1>=d2
    bool operator>=(const Date &d)
    {
        return !(*this < d);
    }

    // d1!=d2
    bool operator!=(const Date &d)
    {
        return !(*this == d);
    }

    // // 因为Date operator=(const Date &d) 出了该函数的作用域*this/d1 还在此时返回的*this是临时拷贝，需要进行拷贝重新开空间造成浪费，不如直接进行&
    // Date operator=(const Date &d)//&d 引用
    // {
    //     if (this != &d)//防止d1=d1进行赋值 此处的&为去地址 ，若this与d的地址一样则无需赋值
    //     {
    //         _year = d._year;
    //         _month = d._month;
    //         _day = d._day;
    //     }

    //     return *this; //*this就是d1
    // }                 // 返回值为了支持连续赋值，保持运算符特性  d3=d1=d2;

private:
    // 成员变量
    int _year;
    int _month;
    int _day;
};

int main()
{
    Date d1(2077, 2, 4);
    Date d2(2222, 3, 2);
    Date d3(2078, 2, 4);

    cout << (d1 < d2) << endl;
    // d3 = d1 = d2;

    d1 = d2;

    d1.Print();

    return 0;
}
