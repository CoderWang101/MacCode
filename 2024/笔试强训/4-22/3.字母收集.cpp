#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // 包含用于求最大值的头文件
using namespace std;

typedef vector<char> VC;
typedef vector<int> VI;

int dx = 1, dy = 1;

// 定义一个函数来计算每个字母的得分
int score(char ch)
{
    if (ch == 'l')
        return 4;
    else if (ch == 'o')
        return 3;
    else if (ch == 'v')
        return 2;
    else if (ch == 'e')
        return 1;
    else
        return 0; // 如果字母不是 'l', 'o', 'v', 'e'，则得分为 0
}

int main()
{
    int m, n;
    cin >> m >> n;

    string tmp;
    vector<VC> s;

    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        // 构造一个新元素
        s.emplace_back();
        for (int j = 0; j < n; j++)
        {
            s.back().push_back(tmp[j]); // 在最后一个 VC 向量中插入字符
        }
        tmp.clear();
    }

    // 初始化动态规划数组
    vector<VI> dp(m, vector<int>(n, 0));

    // 初始化第一个格子的分数
    dp[0][0] = score(s[0][0]);

    // 处理第一行
    for (int j = 1; j < n; j++)
        dp[0][j] = dp[0][j - 1] + score(s[0][j]);

    // 处理第一列
    for (int i = 1; i < m; i++)
        dp[i][0] = dp[i - 1][0] + score(s[i][0]);

    // 动态规划计算其他格子的最大分数
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            // 从上方格子或左方格子走过来
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + score(s[i][j]);
        }
    }

    // 输出最终结果，即右下角的格子的最大分数
    cout << dp[m - 1][n - 1] << endl;

    return 0;
}