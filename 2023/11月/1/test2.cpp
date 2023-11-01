#include <iostream>
#include <assert.h>
using namespace std;

class Array
{
public:
    int &operator[](int i)
    {
        assert(i < 10);

        return _a[i];
    }

    const int &operator[](int i) const
    {
        assert(i < 10);

        return _a[i];
    }

private:
    int _a[10];
    int _size;
};

void Func(const Array &aa)
{
    for (int i = 0; i < 10; i++)
    {
        cout << aa[i] << " ";
    }
}

int main()
{
    Array a;
    for (int i = 0; i < 10; i++)
    {
        a[i] = i;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    Func(a);
    cout << endl;

    return 0;
}