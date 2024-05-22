// 100%
//(xs,ys)找到(xt,yt)的最短路径
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define vc vector<char>
#define vb vector<bool>
#define pii pair<int, int>
#define INF 0x3f3f3f3f

// 方向数组，用于计算相邻节点的坐标变化
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int m, n;
static int count_e;
// 检查节点是否合法
bool isValid(vector<vc> &maze, vector<vb> &vis, int x, int y)
{
    return x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && maze[x][y] == '.';
}

// 使用 BFS 查找最短路径
int bfs(vector<vc> &maze, int xs, int ys, int xt, int yt)
{
    vector<vb> vis(m, vb(n, false));   // 记录节点是否被访问过
    queue<pii> q;                      // 用于 BFS 的队列
    q.push(make_pair(xs - 1, ys - 1)); // 将起点加入队列
    vis[xs - 1][ys - 1] = true;        // 标记起点已被访问
    int steps = 0;                     // 记录步数

    // BFS 主循环
    while (!q.empty())
    {
        int size = q.size(); // 当前层的节点个数
        while (size--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop(); // 弹出当前节点

            // 如果当前节点是终点，则返回步数
            if (x == 'e' && y == 'e')
                return steps;

            // 遍历当前节点的四个相邻节点
            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                // 如果相邻节点合法且未被访问过，则将其加入队列并标记为已访问
                if (isValid(maze, vis, newX, newY))
                {
                    q.push(make_pair(newX, newY));
                    vis[newX][newY] = true;
                }
            }
        }
        steps++; // 步数加一，表示进入下一层
    }
    return -1; // 如果未找到路径，则返回 -1
}

int main()
{
    count_e=0;

    // 输入迷宫的行数和列数，以及起点和终点的坐标
    int xs, ys, xt, yt;
    cin >> m >> n >> xs >> ys >> xt >> yt;

    // 输入迷宫的地图
    vector<vc> maze(m, vc(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];

    // 调用 BFS 函数求解最短路径并输出结果
    int shortest_path = bfs(maze, xs, ys, xt, yt);
    cout << shortest_path << endl;

    return 0;
}
