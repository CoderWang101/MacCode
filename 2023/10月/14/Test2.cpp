//缺省参数只能在定义时给参数，调用时不行
#include <iostream>

using namespace std;
// int main() 
// {
//     int a=10;
//     double b=1.12;
//     char c='c';
// // 可以自动识别变量的类型 cin>>a;
//     cout<<a<<endl;
//     cout<<b<<endl;

//     return 0;
// }

// void Func(int a = 0)
// {
//     cout<<a<<endl;
// }

// int main() 
// {
// Func(); // 没有传参时，使用参数的默认值 Func(10); // 传参时，使用指定的实参
// return 0; 
// }

void Func(int a = 10, int b = 20, int c = 30)
{
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;
}

int main()
{
    Func();
    Func(100,20);
    //Func(, ,30);错误用法，缺省函数只能从头进行更改，不能更改其中某一位置的值

    return 0;
}
