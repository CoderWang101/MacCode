#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    const int MOD = 1e9;
    vector<vector<int> > dp(m, vector<int>(n, 0));

    for (int j = 0; j < n; j++)
        dp[0][j] = 1;

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (j != k)
                {
                    dp[i][j] += dp[i - 1][k];
                    dp[i][j] %= MOD;
                }
            }
        }
    }

    int count = 0;
    for (int j = 0; j < n; j++)
    {
        count += dp[m - 1][j];
        count %= MOD;
    }

    cout << count << endl;

    return 0;
}