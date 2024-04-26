#include <iostream>
using namespace std;
#define int long long

signed main()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (a == 0 || b == 0 || n == 0 || m == 0 || (m <= 1 && n <= 1))
    {
        cout << 0 << endl;
        return 0;
    }

    // 默认a礼包
    if (a < b)
    {
        int tmp = b;
        b = a;
        a = tmp;
        tmp = m;
        m = n;
        n = tmp;
    }
    int counta = 0;
    while (n > 0 && m > 0)
    {
        counta++;
        n -= 2, m -= 1;
    }
    int countb = 0;
    while (n > 0 && m > 0)
    {
        countb++;
        --n, m -= 2;
    }
    cout << counta * a + countb * b << endl;

    return 0;
}
