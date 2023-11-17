#include <iostream>
using namespace std;

// template <class T>
// void Swap(T &x, T &y)
// {
//     T tmp = x;
//     x = y;
//     y = tmp;
// }

// void Swap(double &x, double &y)
// {
//     double tmp = x;
//     x = y;
//     y = tmp;
// }

// void Swap(char &x, char &y)
// {
//     char tmp = x;
//     x = y;
//     y = tmp;
// }

// void Swap(int &x, int &y)
// {
//     int tmp = x;
//     x = y;
//     y = tmp;
// }

// template <class Z>
// Z Add(const Z &left, const Z &right)
// {
//     return left + right;
// }

// template <class T1, class T2, ..., class Tn>
// class 类模板名
// {
//     // 类内成员定义
// };

template <class T>
class Stack
{
private:
    T *_a;
    size_t _top;
    size_t _capaicty;

public:
    Stack(int capaicty = 4)
    {
        _a = new T[capaicty];
        _top = 0;
        _capaicty = capaicty;
    }
    ~Stack()
    {
        delete[] _a;
        _capaicty = _top = 0;
    }
};

int main()
{
    //类只能 显示实例化
    Stack <int>st1;
    Stack <double>st2;

    return 0;
}
// int a1 = 10, a2 = 20;
// double d1 = 10.1, d2 = 22.2;
// cout << Add(a1, a2) << endl;
// cout << Add<int>(a1, d2) << endl;
// cout << Add<double>(d1, a2) << endl;
// cout << Add(d1, d2) << endl;
// double d1 = 2.2;
// double d2 = 3.3;
// Swap(d1, d2);

// int i1 = 1;
// int i2 = 2;
// Swap(i1, i2);

// char a = '0';
// char b = '2';
// Swap(a, b);
// int a=1,b=2;
// Swap(a,b);
// cout<<a<<" "<<b<<endl;

// double aa=1.1,bb=2.1;
// Swap(aa,bb);
// cout<<aa<<" "<<bb<<endl;

// template <class T>
// T Add(const T &left, const T &right)
// {
//     return left + right;
// }
// int main()
// {
//     int a1 = 10, a2 = 20;
//     double d1 = 10.0, d2 = 20.0;
//     Add(a1, a2);
//     Add(d1, d2);
//     /*
//     该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型 通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有一个T， 编译器无法确定此处到底该将T确定为int 或者 double类型而报错
//       注意:在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅
//          Add(a1, d1);
//         */
//     // 此时有两种处理方式:1. 用户自己来强制转化 2. 使用显式实例化
//     Add(a, (int)d);
//     return 0;
// }