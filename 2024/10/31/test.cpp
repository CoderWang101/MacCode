#include <iostream>
#include <vector>
using namespace std;

// 解决 0-1 背包问题的函数
pair<int, vector<int> > knapsack(const vector<int> &values, const vector<int> &weights, int capacity)
{
    int n = values.size();
    // 创建动态规划数组
    vector<vector<int> > dp(n + 1, vector<int>(capacity + 1, 0));

    // 填充 dp 数组
    for (int i = 1; i <= n; ++i)
    {
        for (int w = 1; w <= capacity; ++w)
        {
            if (weights[i - 1] <= w)
            {
                // 选择当前物品或不选择当前物品，取最大值
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
            else
            {
                // 当前物品不能选择，保持不变
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // 获取最大价值
    int max_value = dp[n][capacity];

    // 回溯查找具体物品组合
    vector<int> chosen_items(n, 0);
    int w = capacity;
    for (int i = n; i > 0; --i)
    {
        if (dp[i][w] != dp[i - 1][w])
        { // 当前物品被选中
            chosen_items[i - 1] = 1;
            w -= weights[i - 1];
        }
    }

    return {max_value, chosen_items};
}

int main()
{
    // 输入值
    vector<int> values = {20, 15, 25};
    vector<int> weights = {10, 5, 15};
    int capacity = 20;

    // 计算结果
    auto result = knapsack(values, weights, capacity);
    int max_value = result.first;
    vector<int> chosen_items = result.second;

    cout << "最大价值: " << max_value << endl;
    cout << "选择的物品组合: ";
    for (int i = 0; i < chosen_items.size(); ++i)
    {
        cout << chosen_items[i] << " ";
    }
    cout << endl;

    return 0;
}