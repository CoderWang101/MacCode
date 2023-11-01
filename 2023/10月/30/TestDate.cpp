#include "TestDate.h"

// 判断该月份天数
int Date::GetMonthDay(int year, int month)const
{
    assert(month > 0 && month < 13);

    int monthArray[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0))
    {
        return 29;
    }
    else
        return monthArray[month];
}

Date::Date(int year, int month, int day)
{
    // 判断日期是否合法
    if (month > 0 && month < 13 && (day > 0 && day <= GetMonthDay(year, month)))
    {
        _year = year;
        _month = month;
        _day = day;
    }
    else
    {
        cout << "日期非法" << endl;
    }
}

void Date::Print()const
{
    cout << _year << "/" << _month << "/" << _day << endl;
}

// d1==d2 -> d1.operator==(d2)
bool Date::operator==(const Date &d)const
{
    return _year == d._year && _month == d._month && _day == d._day;
    //    this->_year==d.year
}

// d1<d2
bool Date::operator<(const Date &d)const
{
    return _year < d._year && (_year == d._year && _month < d._month) && (_year == d._year && _month == d._month && _day < d._day);
}

// d1<=d2
bool Date::operator<=(const Date &d)const
{
    return *this < d || *this == d; //*this就是d1
}

// d1>d2
bool Date::operator>(const Date &d)const
{
    return !(*this <= d);
}

// d1>=d2
bool Date::operator>=(const Date &d)const
{
    return !(*this < d);
}

// d1!=d2
bool Date::operator!=(const Date &d)const
{
    return !(*this == d);
}

// d1+=d2
Date &Date::operator+=(int day) // 出作用域*this还在，故用引用返回Date*
{
    //+= --50
    if (day < 0)
    {
        *this -= -day;
        return *this;
    }
    _day += day;
    while (_day > GetMonthDay(_year, _month))
    {
        _day -= GetMonthDay(_year, _month);
        ++_month;
        if (_month == 13)
        {
            ++_year;
            _month = 1;
        }
    }
    return *this;
}

// d1+d2
Date Date::operator+(int day)const
{
    Date tmp(*this); // 拷贝构造函数的定义，拷贝临时对象

    // tmp._day += day;
    // while (tmp._day > GetMonthDay(tmp._year,tmp. _month))
    // {
    //     tmp._day -= GetMonthDay(tmp._year, tmp._month);
    //     ++tmp._month;
    //     if (tmp._month == 13)
    //     {
    //         ++tmp._year;
    //         tmp._month = 1;
    //     }
    // }
    // return tmp;

    tmp += day; // 对Date& operator+=(int day)进行复用
    return tmp;
}

/*
对于第一种实现方式：*this += day，它使用了+=运算符重载，避免了拷贝构造函数的调用，只对当前对象进行了原地修改，因此效率更高。
而对于第二种实现方式：*this = *this + day，它在+运算符重载中使用了拷贝构造函数创建了临时对象tmp，之后又将临时对象赋值给*this，进行了两次拷贝操作，因此效率较低。
所以，第一种实现方式更好。
*/
// Date Date::operator+(int day)
// {
//     Date tmp(*this); // 拷贝构造函数的定义，拷贝临时对象

//     tmp._day += day;
//     while (tmp._day > GetMonthDay(tmp._year,tmp. _month))
//     {
//         tmp._day -= GetMonthDay(tmp._year, tmp._month);
//         ++tmp._month;
//         if (tmp._month == 13)
//         {
//             ++tmp._year;
//             tmp._month = 1;
//         }
//     }
//     return tmp;
// }

// Date& Date::operator+=(int day)
// {
//     *this=*this+day;
//     return *this;
// }

//++d1 返回的是++后的值
Date Date::operator++()
{
    *this += 1;
    return *this;
}
// d2++ 返回的是++前的值 ，由此可得：前置优于后置
Date Date::operator++(int)
{
    Date tmp(*this);
    *this += 1;
    return tmp; // 出作用域销毁无需销毁
}
// d1-=100;
Date &Date::operator-=(int day)
{
    if (day < 0)
    {
        *this -= -day;
        return *this; 
    }

    _day -= day;
    while (_day <= 0)
    {
        --_month;
        if (_month == 0)
        {
            --_year;
            _month = 12;
        }
        _day += GetMonthDay(_year, _month);
    }
    return *this;
}

// d1-100
Date Date::operator-(int day) //const
{
    Date tmp(*this);
    *this -= day;
    return tmp;
}

//--d1
Date Date::operator--()
{
    *this -= 1;
    return *this;
}

// d2--
Date Date::operator--(int)
{
    Date tmp(*this);
    *this -= 1;
    return tmp;
}

// d1-d2
int Date::operator-(const Date &d)const
{
    Date max = *this; // d1
    Date min = d;     // d2
    int flag = 1;

    if (*this < d)
    {
        max = d;
        min = *this;
        flag = -1;
    }

    int n = 0;
    while (min != max)
    {
        ++min;
        ++n;
    }
    return n * flag;
}

// void operator<<(ostream &out,const Date& d)
// {
//     out<<d._year<<"年"<<d._month<<"月"<<d._day<<"日"<<endl;
// }

//➕返回值
// ostream& operator<<(ostream &out,const Date& d)
// {
//     out<<d._year<<"年"<<d._month<<"月"<<d._day<<"日"<<endl;
//     return out;
// }
// istream& operator>>(istream& in,Date& d)
// {
//     in>>d._year>>d._month>>d._day;
//     return in;
// }

