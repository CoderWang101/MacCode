#include <iostream>
#include <vector>
using namespace std;

// 贪心策略，计算多次买卖的最大收益
int max_profit(const vector<int> &prices)
{
    int max_profit = 0;
    // 遍历价格数组，如果后一天的价格比前一天高，就累积收益
    for (size_t i = 1; i < prices.size(); ++i)
        if (prices[i] > prices[i - 1])
            max_profit += prices[i] - prices[i - 1]; // 赚取涨价差额
            
    return max_profit; // 返回累积的最大收益
}

int main()
{
    int n;
    cin >> n;

    if (n <= 1)
    { // 如果数组长度小于等于1，收益为0
        cout << 0 << endl;
        return 0;
    }

    vector<int> prices(n);
    // 输入价格数组
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    int max_profit_value = max_profit(prices); // 计算最大收益
    cout << max_profit_value << endl;          // 输出最大收益

    return 0;
}