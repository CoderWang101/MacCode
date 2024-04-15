// 岛屿个数：搜索（BFS/DFS）
// #include<bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
const int N = 100;

int g[N][N]; // 存地图
int n, m;    // 地图的长和宽

// 避免走重复路造成死循环
bool st_sea[N][N];  // 判断哪个海已经访问过了。
bool st_road[N][N]; // 判断哪个陆地已经访问过了。

// 方向向量
// 海水的方向向量
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

// 陆地的方向向量
int ddx[4] = {-1, 0, 1, 0};
int ddy[4] = {0, 1, 0, -1};
int ans = 0;

// 判断你是否超越了地图的边界。
bool check(int x, int y)
{
    return (x >= 0 and x < n and y >= 0 and y < m);
}

// 找到了x,y所在的岛屿，并且把该岛屿中的其他的1都标记成了true。
void bfs_road(int x, int y)
{
    queue<pii> q;
    st_road[x][y] = true;
    q.push({x, y});
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = t.first + ddx[i];
            int ny = t.second + ddy[i];
            if (check(nx, ny) and g[nx][ny] and !st_road[nx][ny])
            {
                st_road[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

void bfs_sea(int x, int y)
{
    queue<pii> q;
    st_sea[x][y] = true;
    q.push({x, y});
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];
            if (check(nx, ny) and !g[nx][ny] and !st_sea[nx][ny])
            {
                st_sea[nx][ny] = true;
                q.push({nx, ny});
            }

            if (check(nx, ny) and g[nx][ny] and !st_road[nx][ny])
            {
                ans++;
                bfs_road(nx, ny);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;

    ans = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            st_sea[i][j] = st_road[i][j] = false;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            g[i][j] = s[j] - '0';
    }

    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!i || i == n - 1 || !j || j == m - 1)
            {
                if (!g[i][j] && !st_sea[i][j])
                {
                    flag = true;
                    bfs_sea(i, j);
                }
            }
        }
    }
    if (!flag)
        ans = 1;

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}