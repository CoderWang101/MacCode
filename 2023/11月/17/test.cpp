#include <iostream>
using namespace std;

class A
{
public:
    A(int a = 0)
        : _a(a)
    {
        cout << "A():" << this << endl;
    }
    ~A()
    {
        cout << "~A():" << this << endl;
    }

private:
    int _a;
};

// int main()
// {
//     A* p1=new A[10];

//     delete[] p1;

//     return 0;
// }