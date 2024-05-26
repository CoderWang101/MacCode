#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int mid = n / 2;
    int left = mid - 1, right = mid;
    while (right < n && left > 0)
    {
        int sum = right+left;
        if (sum == m)
        {
            cout << left << " " << right << endl;
            --left, ++right;
        }
        else if (sum < m)
            ++right;
        else if (left == m || right == m)
            cout << m << endl;
        else
            --left;
    }

    return 0;
}