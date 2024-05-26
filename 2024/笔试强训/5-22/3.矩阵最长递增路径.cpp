//100%
//这段代码通过动态规划的方法来计算最长递增路径的长度，时间复杂度为O(nm)，空间复杂度为O(nm)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define vc vector<char>
#define vb vector<bool>
#define vi vector<int>
#define pii pair<int, int>
#define INF 0x3f3f3f3f

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int m, n;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 递增路径的最大长度
     * @param matrix int整型vector<vector<>> 描述矩阵的每个数
     * @return int整型
     */

    // 定义方向数组
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int m, n;

    // 深度优先搜索找到以(x, y)为起点的最长递增路径
    int dfs(vector<vi> &maze, vector<vi> &dp, int x, int y)
    {
        int res = 1;
        // 如果已经计算过以(x, y)为起点的最长路径，则直接返回
        if (dp[x][y] != -1)
            return dp[x][y];

        // 遍历四个方向
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            // 检查新位置是否合法，且值比当前位置大
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && maze[newX][newY] > maze[x][y])
                res = max(res, 1 + dfs(maze, dp, newX, newY));// 更新最长路径
        }

        // 记录计算结果
        dp[x][y] = res;
        return res;
    }

    // 解决问题的主函数
    int solve(vector<vi> &matrix)
    {
        // 初始化行列数
        m = matrix.size();
        n = matrix[0].size();
        // 初始化动态规划数组
        vector<vi> dp(m, vector<int>(n, -1));
        int longestPath = 0;

        // 遍历所有位置，找到最长递增路径
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                longestPath = max(longestPath, dfs(matrix, dp, i, j));

        return longestPath;
    }
};

// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// #define vc vector<char>
// #define vb vector<bool>
// #define vi vector<int>
// #define pii pair<int, int>
// #define INF 0x3f3f3f3f

// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};
// int m, n;

// class Solution
// {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      * 递增路径的最大长度
//      * @param matrix int整型vector<vector<>> 描述矩阵的每个数
//      * @return int整型
//      */

//     bool isValid(vector<vi> &maze, vector<vb> &vis, int x, int y)
//     {
//         return x >= 0 && x < m && y >= 0 && y < n && !vis[x][y];
//     }

//     // 确认四周可走
//     bool iswalk(vector<vi> &maze, vector<vb> &vis, int x, int y)
//     {
//         for (int i = 0; i < 4; i++)
//         {
//             int wx = x + dx[i];
//             int wy = y + dy[i];
//             if (isValid(maze, vis, wx, wy) && maze[wx][wy] > maze[x][y])
//             {
//                 return true;
//             }
//         }
//         return false;
//     }

//     int bfs(vector<vi> &maze, int x, int y)
//     {
//         vector<vb> vis(m, vb(n, false));
//         queue<pii> q;
//         q.push(make_pair(x - 1, y - 1));
//         int steps = 0;

//         while (!q.empty())
//         {
//             int size = q.size();
//             while (size--)
//             {
//                 int x = q.front().first;
//                 int y = q.front().second;
//                 q.pop();

//                 //四周不可走时,返回步数
//                 if(!iswalk(maze,vis,x,y))
//                     return steps;

//                 // 确认四周可走
//                 for (int i = 0; i < 4; i++)
//                 {
//                     int newX = x + dx[i];
//                     int newY = y + dy[i];
//                     if (isValid(maze, vis, newX, newY) && maze[newX][newY] > maze[x][y])
//                     {
//                         q.push(make_pair(newX,newY));
//                         vis[newX][newY]=true;
//                     }
//                 }
//             }
//             ++steps;
//         }
//     }

//     int solve(vector<vi> &matrix)
//     {
//         m = n = 1005;
//         int x = matrix.size(), y = matrix[0].size();
//         int longer_path = bfs(matrix, x, y);

//         return longer_path;
//     }
// };
