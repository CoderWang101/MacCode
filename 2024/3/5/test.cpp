#include <iostream>
using namespace std;

template <class T>
struct MyLess
{
    bool operator()(const T &x, const T &y)
    {
        return x < y;
    }
};

int main()
{
    MyLess<int> lessFunc;
    cout << lessFunc(1, 2) << endl;

    return 0;
}