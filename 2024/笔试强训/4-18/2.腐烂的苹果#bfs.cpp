#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef vector<bool> VB;
typedef vector<int> VI;
typedef pair<int, int> PII;

class Solution
{

    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    bool vis[1001][1001] = {0};
    int m, n;

public:
    void bfs(vector<VI> &grid, queue<PII> &q, int &ret)
    {
        while (q.size())
        {
            int sz = q.size();
            ret++;
            while (sz--)
            {
                int a = q.front().first, b = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int x = a + dx[i], y = b + dy[i];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] == 1)
                    {
                        vis[x][y] = true;
                        q.push(make_pair(x, y));
                    }
                }
            }
        }
    }

    int rotApple(vector<VI> &grid)
    {
        m = grid.size(), n = grid[0].size();
        queue<PII> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 2 && !vis[i][j]) // 只处理未访问过的苹果
                    q.push(make_pair(i, j));
        
        //腐蚀所有苹果的时间
        int ret = 0;
        bfs(grid, q, ret);

        // 查找是否有没被腐蚀的苹果
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1 && !vis[i][j])
                    return -1;

        return ret - 1;
    }
};