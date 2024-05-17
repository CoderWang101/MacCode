#include <iostream>
using namespace std;

int n,m;

int slove()
{
    int a = 1, ret = 0;
    while (n)
    {
        n -= a;
        ++ret;
        if (n % (2 * a) == 0)
            a *= 2;
    }
    return ret;
}

int main()
{
    cin>>m;
    while (m--)
    {
        cin >> n;

        int ret = slove();
        cout << ret << endl;
    }

    return 0;
}