#include <iostream>
#include <vector>
using namespace std;

int ret;

int slove(vector<int> &a, int n)
{
    int pos = 0;
    ret = 0;

    while (pos < n)
    {
        if (pos == n - 1)
        {
            ++ret;
            break;
        }
        if (a[pos] < a[pos + 1])
        {
            while (pos + 1 < n && a[pos] <= a[pos + 1])
                ++pos;
            ++ret;
        }
        else if (a[pos] > a[pos + 1])
        {
            while (pos + 1 < n && a[pos] >= a[pos + 1])
                ++pos;
            ++ret;
        }
        else
            while (pos + 1 < n && a[pos] == a[pos + 1])
                ++pos;

        ++pos;
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    if (n == 0)
        return 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << slove(a, n) << endl;

    return 0;
}
