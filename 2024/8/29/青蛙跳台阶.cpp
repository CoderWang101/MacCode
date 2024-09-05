#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main()
{
    int n = 5; // 计算阶乘到 n

    vector<ll> dp(n + 1); // 初始化阶乘数组，长度 n+1
    dp[0] = 1,dp[1]=1,dp[1] = 2; // 0! = 1
    for (int i = 3; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2]; // 根据阶乘公式计算
    }

    // 输出从 1 到 n 的阶乘
    for (int i = 0; i <= n; ++i)
    {
        cout << "Factorial of " << i << " is " << dp[i] << endl;
    }

    return 0;
}