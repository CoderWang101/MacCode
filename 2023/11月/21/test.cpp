#include <iostream>
// using namespace std;

// namespace example
// {
//     const int Sum(int &x, int &y)
//     {
//         return x + y;
//     }

//     void Add(const int val, const int constant)
//     {
//         int result = val + constant;
//         cout << "Result: " << result << endl;
//     }
//     class MyClass
//     {
//     public:
//         int getValue() const;

//         // const char& operator[](size_t pos) const
//         // {
//         //     return _str[pos];
//         // }

//     private:
//         int value;
//         char* _str;
//     };

//     int MyClass::getValue() const
//     {
//         return value; // 只能读取成员变量的值
//     }
// }

// int main()
// {
//     int x = 1, y = 2;

//     int val = example::Sum(x, y);
//     cout << val << endl;

//     return 0;
// }

// class MyString
// {
// public:
//     MyString(const char *str)
//     {
//         _str = new char[std::strlen(str) + 1];
//         std::strcpy(_str, str);
//     }

//     // 错误的 const 成员函数
//     char &operator[](size_t pos) const
//     {
//         return _str[pos]; // 修改了成员变量值
//     }

// private:
//     char *_str;
// };

// int main()
// {
//     const MyString str("Hello");

//     str[0] = 'h'; // 错误：试图修改常量对象的值

//     return 0;
// }

class Date
{
public:
    Date(int year, int month, int day) : _year(year), _month(month), _day(day) {}

    // 错误的拷贝构造函数，没有使用 const 修饰符
    Date(Date &d)
    {
        _year = d._year + 1;
        _month = d._month;
        _day = d._day;
    }

    void PrintDate()
    {
        std::cout << "Year: " << _year << ", Month: " << _month << ", Day: " << _day << std::endl;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    Date d1(2023, 11, 21);
    d1.PrintDate(); // 输出：Year: 2023, Month: 11, Day: 21

    Date d2 = d1;   // 调用拷贝构造函数
    d2.PrintDate(); // 输出：Year: 2024, Month: 11, Day: 21

    return 0;
}