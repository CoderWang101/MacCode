// #include <iostream>
// using namespace std;

// class A
// {
// public:
//     // const 修饰*this
//     // this的类型变成const A*
//     void Print() const
//     {
//         cout << _a << endl;
//     }
//     //内部不改变成员变量的成员函数
//     //最好加上const，const对象和普通对象都可以调用
    

// private:
//     int _a = 10;
// };

// void Func(const A& x)
// {
//     x.Print();
// }

// int main()
// {
//     const A aa;
//     //aa.Print(); // 报错 ->权限放大 ；
//     Func(aa);

//     return 0;
// }