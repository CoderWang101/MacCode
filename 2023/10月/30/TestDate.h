#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
    // 友元函数
    // friend void operator<<(ostream &out, const Date &d);
    friend ostream &operator<<(ostream &out, const Date &d);

    friend istream &operator>>(istream &in, Date &d); // 不能加const，为输出型参数

public:
    int GetMonthDay(int year, int month) const;

    // 构造函数
    Date(int year = 1, int month = 1, int day = 1);

    void Print() const;

    // d1==d2 -> d1.operator==(d2)
    bool operator==(const Date &d) const;

    // d1<d2
    bool operator<(const Date &d) const;

    // d1<=d2
    bool operator<=(const Date &d) const;

    // d1>d2
    bool operator>(const Date &d) const;

    // d1>=d2
    bool operator>=(const Date &d) const;

    // d1!=d2
    bool operator!=(const Date &d) const;

    // d1+=100
    Date &operator+=(int day);

    // d1+100
    Date operator+(int day) const;

    // d1-=100;
    Date &operator-=(int day);

    // d1-100
    Date operator-(int day) ;

    //++d1
    Date operator++();

    // d2++
    Date operator++(int); //()内参数(int)无实际意义

    //--d1
    Date operator--();

    // d2--
    Date operator--(int); //()内参数(int)无实际意义

    // d1-d2
    int operator-(const Date &d) const;

private:
    // 成员变量
    int _year;
    int _month;
    int _day;
};

// void operator<<(ostream &out, const Date &d);
// 为了支持连续调用➕返回值
// ostream &operator<<(ostream &out, const Date &d); // 加const是为了减少拷贝

// 流提取
// istream &operator>>(istream &in, Date &d); // 不能加const，为输出型参数

// 直接用内联函数进行定义，无需在对其他.cpp进行链接
inline ostream &operator<<(ostream &out, const Date &d)
{
    out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
    return out;
}
inline istream &operator>>(istream &in, Date &d)
{
    in >> d._year >> d._month >> d._day;
    return in;
}
// 类里面短小函数，适合做内联的函数，直接是在类里面定义