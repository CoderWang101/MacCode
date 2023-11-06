// #include <iostream>

// class A
// {
// public:
//     explicit A(int a)
//         : _a1(a)
//     {
//         cout << "A(int a)" << endl;
//     }
//     A(int a1, int a2)
//         : _a1(a1), _a2(a2)
//     {
//     }

//     A(const A &aa)
//         : _a1(aa._a1)
//     {
//         cout << "A(const A& aa)" << endl;
//     }

// private:
//     int _a2;
//     int _a1;
// };

// int main()
// {
//     // 多参数构造函数
//     A aa2(1, 1);
//     A aa3 = {2, 2};

//     return 0;
// }

// class Date
// {
// public:
//     //  虽然有多个参数，但是创建对象时后两个参数可以不传递，没有使用explicit修饰，具 有类型转换作用
//     // explicit修饰构造函数，禁止类型转换
//     explicit Date(int year, int month = 1, int day = 1)
//         : _year(year), _month(month), _day(day)
//     {
//     }
//     Date &operator=(const Date &d)
//     {
//         if (this != &d)
//         {
//             _year = d._year;
//             _month = d._month;
//             _day = d._day;
//         }
//         return *this;
//     }

// private:
//     int _year;
//     int _month;
//     int _day;
// };
// void Test()
// {
//     Date d1(2022);
//     // 用一个整形变量给日期类型对象赋值
//     // 实际编译器背后会用2023构造一个无名对象，最后用无名对象给d1对象进行赋值 d1 = 2023;
//     // 将1屏蔽掉，2放开时则编译失败，因为explicit修饰构造函数，禁止了单参构造函数类型转 换的作用
// }

// using std::cout;
// using std::endl;

// int count = 0;

// class A
// {
// public:
//     A(int a = 0)
//     {
//         ++count;
//     }

//     A(const A &aa)
//     {
//         ++count;
//     }
// };

// void func(A)
// {
// }

// int main()
// {
//     A aa1;
//     A aa2(aa1);

//     func(aa1);

//     A aa3 = 1;

//     cout<<count<<endl;

//     return 0;
// }

// using std::cout;
// using std::endl;
// using namespace std;

// class A
// {
// public:
//     A(int a = 0)
//     {
//         ++count;
//     }

//     A(const A &aa)
//     {
//         ++count;
//     }

//     // 静态成员函数 -- 没有this指针
//     static int GetCount()
//     {
//         // a++;没有this指针，不能直接访问
//         return count;
//     }

// private:
//     static int count;
// };

// int A::count = 0; // 定义初始化

// void func(A)
// {
// }

// int main()
// {
//     // A aa1;
//     // A aa2(aa1);
//     // func(aa1);
//     // A aa3 = 1;
//     A aa4[10];// 10

//     cout << A::GetCount() << endl;

//     return 0;
// }

// class Sum
// {
// public:
//     Sum()
//     {
//         _sum += _i;
//         ++_i;
//     }
//     static int GetSum()
//     {
//         return _sum;
//     }

// private:
//     static int _i;
//     static int _sum;
// };

// int Sum::_i = 1;
// int Sum::_sum = 0;

// class Solution
// {
// public:
//     int Sum_Solution(int n)
//     {
//         Sum *ptr = new Sum[n];

//         return Sum::GetSum();
//     }
// };

// A func()
// {
//     int n;

// }

// int main()
// {
//     Solution s;
//     cout<<Solution().Sum_Solution(10)<<endl;

//     //匿名对象，声明周期只在这一行
//     Solution();
//     Sum();

//     return 0;
// }

// class Date
// {
// public:
//     Date(int year, int month, int day)
//         : _year(year), _month(month), _day(day)
//     {
//     }
//     // d1 << cout; -> d1.operator<<(&d1, cout); 不符合常规调用 // 因为成员函数第一个参数一定是隐藏的this，所以d1必须放在<<的左侧
//     ostream &operator<<(ostream &_cout)
//     {
//         _cout << _year << "-" << _month << "-" << _day << endl;
//         return _cout;
//     }

// private:
//     int _year;
//     int _month;
//     int _day;
// };

// class Date
// {
//     friend ostream &operator<<(ostream &_cout, const Date &d);
//     friend istream &operator>>(istream &_cin, Date &d);

// public:
//     Date(int year = 1900, int month = 1, int day = 1)
//         : _year(year), _month(month), _day(day)
//     {
//     }

// private:
//     int _year;
//     int _month;
//     int _day;
// };

// ostream &operator<<(ostream &_cout, const Date &d)
// {
//     _cout << d._year << "-" << d._month << "-" << d._day;
//     return _cout;
// }
// istream &operator>>(istream &_cin, Date &d)
// {
//     _cin >> d._year;
//     _cin >> d._month;
//     _cin >> d._day;
//     return _cin;
// }
// int main()
// {
//     Date d;
//     cin >> d;
//     cout << d << endl;
//     return 0;
// }

// class Time
// {
//     friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类 中的私有成员变量
// public:
//     Time(int hour = 0, int minute = 0, int second = 0)
//         : _hour(hour), _minute(minute), _second(second)
//     {
//     }

// private:
//     int _hour;
//     int _minute;
//     int _second;
// };

// class Date
// {
// public:
//     Date(int year = 1900, int month = 1, int day = 1)
//         : _year(year), _month(month), _day(day)
//     {
//     }
//     void SetTimeOfDate(int hour, int minute, int second)
//     {
//         // 直接访问时间类私有的成员变量 _t._hour = hour; _t._minute = minute; _t._second = second;
//     }

// private:
//     int _year;
//     int _month;
//     int _day;
//     Time _t;
// };

// #include <iostream>
// using namespace std;

// class A
// {
// private:
//     int h;
//     static int k;

// public:
//     // 内部类
//     class B
//     {
//     public:
//         void func(const A& a)
//         {
//             cout<<k<<endl;
//             cout<<a.h<<endl;
//         }
//     private:
//         int b;
//     };
// };

// // 静态成员变量的定义和初始化
// int A::k = 1;

// int main()
// {
//     A aa;
//     cout<<sizeof(aa)<<endl;

//     // 访问B
//     A::B b;
//     b.func(aa);

//     return 0;
// }

// #include <iostream>

// class A
// {
// private:
//     int h = 1;
//     static int k;
//     class B
//     {
//     public:
//         void func(const A &a)
//         {
//             std::cout << k << std::endl;
//             std::cout << a.h << std::endl;
//         }

//     private:
//         int b;
//     };

// public:

// };

// // 静态成员变量的定义和初始化
// int A::k = 90;

// int main()
// {
//     A aa;
//     // std::cout << sizeof(aa) << std::endl;

//     // 访问B
//     // A::B b;
//     // b.func(aa); // 90 1

//     return 0;
// }

#include <iostream>
using namespace std;

// class A
// {
// public:
//     A(int a = 0)
//         : _a(a)
//     {
//         cout << "A(int a)" << endl;
//     }
//     A(const A &aa)
//         : _a(aa._a)
//     {
//         cout << "A(const A& aa)" << endl;
//     }
//     A &operator=(const A &aa)
//     {
//         cout << "A& operator=(const A& aa)" << endl;
//         if (this != &aa)
//         {
//             _a = aa._a;
//         }
//         return *this;
//     }
//     ~A()
//     {
//         cout << "~A()" << endl;
//     }

// private:
//     int _a;
// };
// void f1(A aa)
// {}
// A f2()
// {
//     A aa;
//     return aa;
// }
// int main()
// {
//     // 传值传参
//     A aa1;
//     f1(aa1);
//     cout << endl;
//     // 传值返回 f2();
//     cout << endl;
//     // 隐式类型，连续构造+拷贝构造->优化为直接构造 f1(1);
//     // 一个表达式中，连续构造+拷贝构造->优化为一个构造 f1(A(2));
//     cout << endl;
//     // 一个表达式中，连续拷贝构造+拷贝构造->优化一个拷贝构造 A aa2 = f2();
//     cout << endl;
//     // 一个表达式中，连续拷贝构造+赋值重载->无法优化 aa1 = f2();
//     cout << endl;
//     return 0;
// }

class A
{
public:
    A(int a = 0)
        : _a(a)
    {
        cout << "A(int a)" << endl;
    }
    A(const A &aa)
        : _a(aa._a)
    {
        cout << "A(const A& aa)" << endl;
    }
    A &operator=(const A &aa)
    {
        cout << "A& operator=(const A& aa)" << endl;
        if (this != &aa)
        {
            _a = aa._a;
        }
        return *this;
    }
    ~A()
    {
        cout << "~A()" << endl;
    }

private:
    int _a;
};
void f1(A aa)
{
}
A f2()
{
    A aa;
    return aa;
}

void func1(A aa)
{
}
// 使用引用传参
void func2(const A &aa) // 临时对象，匿名对象具有常性，加const
{
}

// int main()
// {
//     A aa1=1;//构造+拷贝构造-> 直接优化为构造
//     func1(aa1);//无优化 A(const A& aa)
//     func1(2);//构造+拷贝构造-> 直接优化为构造
//     func1(A(2));//构造+拷贝构造-> 直接优化为构造

//     cout<<"-------------------------------"<<endl;
//     //引用传参
//     func2(aa1);//无优化 ，无需拷贝
//     //临时对象，匿名对象具有常性，func2要加const
//     func2(2);//无优化 ，无需拷贝
//     func2(A(3));//无优化，无需拷贝

//     return 0;
// }

A func3()
{
    A aa;      // 构造
    return aa; // 出函数被销毁 ，创建临时变量进行拷贝构造，若出现析构，则为aa，进行了析构
}
// func3();//构造+拷贝构造

// A aa1=func3();//func3进行一次拷贝构造，aa1=func3再进行一次拷贝构造，优化为一个拷贝构造

A func4()
{
    return A();
}

int main()
{
    func4();
    A aa2 = func4();
    cout <<"==========="<<endl;
    A aa3;
    aa3=func3();

    return 0;
}