#include <iostream>
using namespace std;
// class Date
// {
// public:
//     void Init(int year, int month, int day)
//     {
//         _year = year;
//         _month = month;
//         _day = day;
//     }
//     void Print()
//     {
//         cout << _year << "-" << _month << "-" << _day << endl;
//     }

// private:
//     int _year;
//     int _month;
//     int _day;
// };

// int main()
// {
//     Date d1;
//     d1.Init(2022, 7, 5);
//     d1.Print();
//     Date d2;
//     d2.Init(2022, 7, 6);
//     d2.Print();
//     return 0;
// }

// class Stack
// {
// public:
//     Stack()
//     {
//         _a=nullptr;
//         _size=_capacity=0;
//     }

//     Stack(int n)
//     {
//         _a=(int*)malloc(sizeof(int)*n);
//         _size=_capacity=0;
//     }

//     void Init(int n=4)
//     {
//         _a=(int*)malloc(sizeof(int)*n);
//         if (nullptr==_a)
//         {
//             perror("malloc is fail");
//             return;
//         }
//         _capacity=n;
//         _size=0;
//     }

//     void Push(int x)
//     {
//         //...
//         a[_size++]=x;
//     }
//     //...

//     ~Stack()
//     {
//         free(_a);
//         _a=nullptr;
//         _size=_capacity=0
//     }

// private:
//     int _a;
//     int _size;
//     int _capacity;
// };

// int main()
// {
//     Stack st;//无参
//    //Stack st();//有参

//     st.Push(1);
//     st.Push(2);
//     st.Push(3);
//     st.Push(4);

//     st.Dstory();

//     return 0;
// }

// typedef int DataType;
// class Stack
// {
// public:
//     Stack(size_t capacity = 3)
//     {
//         _array = (DataType *)malloc(sizeof(DataType) * capacity);
//         if (NULL == _array)
//         {
//             perror("malloc申请空间失败!!!");
//             return;
//         }
//         _capacity = capacity;
//         _size = 0;
//     }
//     void Push(DataType data)
//     {
//         // CheckCapacity();
//         _array[_size] = data;
//         _size++;
//     }
//     // 其他方法...
//     ~Stack()
//     {
//         if (_array)
//         {
//             free(_array);
//             _array = NULL;
//             _capacity = 0;
//             _size = 0;
//         }
//     }

// private:
//     DataType *_array;
//     int _capacity;
//     int _size;
// };
// void TestStack()
// {
//     Stack s;
//     s.Push(1);
//     s.Push(2);
// }

// class Date
// {
// public:
//     // Date()
//     // {

//     // }
//     Date(int year=1,int month=1,int day=1)
//     {
//         _year=1;
//         _month=1;
//         _day=1;
//     }

//     void print()
//     {
//         cout<<_year<<"/"<<_month<<"/"<<_day<<endl;
//     }

// private:
//     //成员变量
//     int _year=1;
//     int _month=1;
//     int _day=1;
// };

// class Date
// {
// public:
//     //内置类型成员不做处理
//     void print()
//     {
//         cout<<_year<<"/"<<_month<<"/"<<_day<<endl;
//     }

// private:
//     // 基本类型/内置类型 - 不进初始化
//     int _year;
//     int _month;
//     int _day;
// };

// class MyQueue
// {
//     // 默认生成析构函数，对自定义类型，会调用它的析构函数
//     void push(int x);
//     {

//     }
//     Stack _pushST();
//     Stack _popST();
// };

// int main()
// {
//     //Date d1;
//     Date d1;
//     d1.print();

//     MyQueue q;

//     return 0;
// }

// class Date
// {
// public:
//     Date(int year = 2077, int month = 10, int day = 12)
//     {
//         _year = year;
//         _month = month;
//         _day = day;
//     }

//     Date(const Date& d)
//     {
//         cout<<"Date(Date& d);"<<endl;
//         _year = d._year;
//         _month = d._month;
//         _day = d._day;
//     }

// private:
//     int _year;
//     int _month;
//     int _day;
// };

// int main()
// {
//     Date d1(2023, 2, 3);
//     //两种拷贝方式
//     Date d2(d1); // 使用拷贝构造函数创建对象 d2，并将 d1 的值拷贝到 d2 中
//     Date d3=d1;

//     return 0;
// }

// class Date
// {
// public:
//     Date(int year, int minute, int day)
//     {
//         cout << "Date(int,int,int):" << this << endl;
//     }
//     Date(const Date &d)//拷贝构造
//     {
//         cout << "Date(const Date& d):" << this << endl;
//     }
//     ~Date()//析构函数
//     {
//         cout << "~Date():" << this << endl;
//     }

// private:
//     int _year;
//     int _month;
//     int _day;
// };

// Date Test(Date d)
// {
//     Date temp(d);
//     return temp;
// }
// int main()
// {
//     Date d1(2022, 1, 13);
//     Test(d1);
//     return 0;
// }

// class Date
// {
// public:
//     Date(int year = 2077, int month = 10, int day = 12)
//     {
//         _year = year;
//         _month = month;
//         _day = day;
//     }

//     Date(const Date& d)
//     {
//         cout<<"Date(Date& d);"<<endl;
//         _year = d._year;
//         _month = d._month;
//         _day = d._day;
//     }
//     Date(const Date* d)
//     {
//         cout<<"Date(Date& d);"<<endl;
//         _year = d._year;
//         _month = d._month;
//         _day = d._day;
//     }

// private:
//     int _year;
//     int _month;
//     int _day;
// };

// int main()
// {
//     Date d1(2023, 2, 3);

//     Date d2(&d1); 
//     Date d3=&d1;

//     return 0;
// }


