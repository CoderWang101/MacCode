// // #include <iostream>

// // class Compare
// // {
// // private:
// //     int _num;

// // };

// // template <class T>
// // int Max(T left, T right)
// // {
// //     return left > right ? left : right;
// // }

// // template <>
// // int Max<Compare *>(Compare *left, Compare *right)
// // {
// //     return *left > *right ? *left : *right;
// // }
#include <iostream>
using namespace std;

// class Compare
// {
// private:
//     int _num;

// public:
//     Compare(int x)
//         : _num(x)
//     {
//     }

//     bool operator<(const Compare &other) const
//     {
//         return _num < other._num;
//     }

//     friend ostream &operator<<(ostream &os, const Compare &cmp)
//     {
//         os << cmp._num;
//         return os;
//     }
// };

// template <class T>
// T Max(T left, T right)
// {
//     return left < right ? right : left;
// }

// template <>
// Compare *Max<Compare *>(Compare *left, Compare *right)
// {
//     return *left < *right ? right : left;
// }

// Compare Max(Compare left, Compare right)
// {
//     return left < right ? right : left;
// }

// int main()
// {
//     Compare n1(50);
//     Compare n2(2);
//     Compare n3(10);

//     Compare result = Max(n3, n1);

//     cout << "Max of a and b: " << Max(&n1, &n2) << endl;
//     cout << "Max of a and b: " << result << endl;

//     return 0;
// }

// 模板类Data，T1和T2分别代表两个类型
template <class T1, class T2>
class Data
{
public:
    // 构造函数，打印出模板类的类型
    Data() { cout << "Data<T1, T2>" << endl; }

private:
    T1 _d1;
    T2 _d2;
};

// 模板类Data，T1和T2分别代表两个类型，int和char
template <>
class Data<int, char>
{
public:
    Data() { cout << "Data<int, char>" << endl; }

private:
    int _d1;
    char _d2;
};

// 部分偏特化
template <class T>
class Data<int, T>
{
public:
    Data() { cout << "Data<int, T>" << endl; }

private:
    int _d1;
    float _d2;
};

// 对参数限制
template <class T1, class T2>
class Data<T1 *, T2 *>
{
public:
    Data()
    {  cout << "指针类型Data<*,*>" << endl; }

private:
    T1 *_d1;
    T2 *_d2;
};

template <class T1, class T2>
class Data<T1 &, T2 &>
{
    public:
    Data()
    { cout << "引用类型Data<&,&>" << endl; }

private:
    T1 _d1;
    T2 _d2;
};

void TestVector()
{
    Data<int, char> d1;
    Data<int, int> d2;
    Data<int, long> d3;

    Data<int *, char *> d4;6
    Data<int &, char &> d5;
}

int main()
{
    TestVector();

    return 0;
}