#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
public:
    int GetMonthDay(int year, int month);
    // 构造函数
    Date(int year = 1, int month = 1, int day = 1);
    void Print();

    // d1==d2 -> d1.operator==(d2)
    bool operator==(const Date &d);

    // d1<d2
    bool operator<(const Date &d);

    // d1<=d2
    bool operator<=(const Date &d);

    // d1>d2
    bool operator>(const Date &d);

    // d1>=d2
    bool operator>=(const Date &d);

    // d1!=d2
    bool operator!=(const Date &d);

    // d1+=100
    Date &operator+=(int day);

    // d1+100
    Date operator+(int day);

    // d1-=100;
    Date &operator-=(int day);

    // d1-100
    Date operator-(int day);

    //++d1
    Date operator++();

    // d2++
    Date operator++(int); //()内参数(int)无实际意义
   
    //--d1
    Date operator--();

    // d2--
    Date operator--(int); //()内参数(int)无实际意义

    // d1-d2
    int operator-(const Date &d);

private:
    // 成员变量
    int _year;
    int _month;
    int _day;
};