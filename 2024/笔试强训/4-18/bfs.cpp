#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
    typedef pair<int, int> PII;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool vis[301][301];
    int m, n;

public:
    void bfs(vector<string> &grid, int i, int j)
    {
        queue<PII> q;
        //  dfq.push({i,j});//插入第一个节点
        q.push(make_pair(i, j));
        vis[i][j] = true;

        while (q.size())
        {
            auto [a, b] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int x = a + dx[k], y = b + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1' && !vis[x][y])
                {
                    // q.push({x,y});
                    q.push(make_pair(x, y));//符合条件,进行插入
                    vis[x][y] = true;
                }
            }
        }
    }

    int numIslands(vector<string> &grid)
    {
        m = grid.size(), n = grid[0].size();
        int ret = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; j++)
            {
                ret++;
                bfs(grid, i, j);
            }
        }
        return ret;
    }
};