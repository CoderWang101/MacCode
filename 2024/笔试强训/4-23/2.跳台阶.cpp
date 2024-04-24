#include <iostream>
using namespace std;

int dp[40] = {0};

int main()
{
    dp[0] = 0, dp[1] = 1, dp[2] = 2;
    int n;
    cin >> n;

    if (n == 1)
        cout << dp[1] << endl;
    if (n == 2)
        cout << dp[2] << endl;
    if (n == 1 || n == 2)
        return 0;

    for (int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    cout << dp[n] << endl;

    return 0;
}