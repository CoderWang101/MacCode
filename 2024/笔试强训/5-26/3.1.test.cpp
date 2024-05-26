#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define vi vector<int>

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// 检查是否有被搜索
bool isValid(vector<vi> &maze, int x, int y, int m, int n)
{
    return x >= 0 && x < m && y >= 0 && y < n;
}

int dfs(vector<vi> &maze, vector<vi> &dp, int x, int y, int m, int n)
{
    if (dp[x][y] != 0)
        return dp[x][y];

    int max_len = 1;

    for (int i = 0; i < 4; i++)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (isValid(maze, newx, newy, m, n) && maze[x][y] > maze[newx][newy])
        {
            int step = 1 + dfs(maze, dp, newx, newy, m, n);
            max_len = max(max_len, step);
        }
    }
    dp[x][y] = max_len;
    return max_len;
}

int longestSlidePath(vector<vi> &maze)
{
    int m = maze.size();
    if (m == 0)
        return 0;
    int n = maze[0].size();
    
    vector<vi> dp(m, vi(n, 0));

    int longestPath = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int pathLength = dfs(maze, dp, i, j, m, n);
            longestPath = max(longestPath, pathLength);
        }
    }
    return longestPath;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vi> maze(m, vi(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];

    int longestPath = longestSlidePath(maze);
    cout << longestPath << endl;

    return 0;
}