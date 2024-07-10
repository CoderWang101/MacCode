//100%
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int count_max = 0;
    int left = 0, right = 0, rightR = 0, len = 0;

    while (right < n)
    {
        rightR = right + 1;
        if (v[rightR] - v[right] > 8 && rightR < n)
        {
            count_max = max(count_max, rightR - left);
            left = rightR;
        }
        else if (right == n - 1) // 边界检查
            count_max = max(count_max, right - left);

        ++right;
    }
    count_max = max(count_max, right - left);
    cout << count_max << endl;

    return 0;
}