#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define vi vector<int>

// 定义上下左右四个方向的偏移量
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int m, n; // 矩阵的行数和列数

// 检查一个点是否在矩阵范围内
bool isValid(vector<vi> &maze, int x, int y)
{
    return x >= 0 && x < m && y >= 0 && y < n;
}

// 深度优先搜索函数，用于计算从某个点出发的最长滑道长度
int dfs_dp(vector<vi> &maze, vector<vi> &dp, int x, int y)
{
    // 如果当前点已经被搜索过，则直接返回之前计算的结果
    if (dp[x][y] != 0)
        return dp[x][y];

    int max_len = 1; // 初始长度为1，因为至少包括当前点

    // 遍历当前点的四个相邻点
    for (int i = 0; i < 4; i++)
    {
        int newx = x + dx[i]; // 计算相邻点的坐标
        int newy = y + dy[i];

        // 如果相邻点在矩阵范围内且高度更低，则继续向下搜索
        if (isValid(maze, newx, newy) && maze[x][y] > maze[newx][newy])
        {
            int step = 1 + dfs_dp(maze, dp, newx, newy); // 递归计算从相邻点出发的最长滑道长度
            max_len = max(max_len, step);                // 更新当前点的最长滑道长度
        }
    }
    dp[x][y] = max_len; // 将当前点的最长滑道长度记录在dp数组中，避免重复计算
    return max_len;
}

int main()
{
    cin >> m >> n;             // 输入矩阵的行数和列数
    vector<vi> maze(m, vi(n)); // 创建矩阵

    // 输入矩阵的元素值
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];

    vector<vi> dp(m, vi(n, 0)); // 创建用于记录最长滑道长度的dp数组，初始值为0

    int long_path = 0; // 记录整个滑雪场中最长的滑道长度

    // 遍历矩阵中的每个点，计算从该点出发的最长滑道长度，并更新long_path
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int tmp = dfs_dp(maze, dp, i, j); // 计算从当前点出发的最长滑道长度
            long_path = max(long_path, tmp);  // 更新整个滑雪场中最长的滑道长度
        }
    }

    cout << long_path << endl; // 输出结果

    return 0;
}