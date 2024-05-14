//100%
#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

signed main()
{
    int n;
    cin >> n;

    vector<int> num(n);
    vector<int> dp(n);

    for (int i = 0; i < n; i++)
        cin >> num[i];

    if (n == 1)
    {
        cout << num[0] << endl;
        return 0;
    }

    dp[0] = num[0];
    dp[1] = max(num[0], num[1]);

    for (int i = 2; i < n; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + num[i]);

    cout << dp[n - 1] << endl;

    return 0;
}