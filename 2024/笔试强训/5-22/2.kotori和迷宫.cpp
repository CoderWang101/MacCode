//60%
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define vc vector<char>
#define vb vector<bool>
#define pii pair<int, int>
#define INF 0x3f3f3f3f

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int m, n;

bool isValid(vector<vc> &maze, vector<vb> &vis, int x, int y)
{
    return x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && maze[x][y] != '*';
}

pair<int, int> bfs(vector<vc> &maze, int xs, int ys)
{
    vector<vb> vis(m, vb(n, false));
    queue<pair<pii, int> > q;
    q.push({{xs, ys}, 0});
    vis[xs][ys] = true;

    int exitCount = 0;
    int shortestPath = INF;

    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        int x = cur.first.first;
        int y = cur.first.second;
        int steps = cur.second;

        if (maze[x][y] == 'e')
        {
            exitCount++;
            shortestPath = min(shortestPath, steps);
        }

        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValid(maze, vis, newX, newY))
            {
                q.push({{newX, newY}, steps + 1});
                vis[newX][newY] = true;
            }
        }
    }

    return {exitCount, shortestPath};
}

int main()
{
    int xs, ys;
    cin >> m >> n;

    vector<vc> maze(m, vc(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'k')
            {
                xs = i;
                ys = j;
            }
        }
    }

    pair<int, int> result = bfs(maze, xs, ys);

    if (result.first > 0)
    {
        cout << result.first-1 << " " << result.second << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// #define vc vector<char>
// #define vb vector<bool>
// #define pii pair<int, int>
// #define INF 0x3f3f3f3f

// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};
// bool vis[35][35] = {false};
// int m, n;

// bool isVialid(vector<vc> &maze, vector<vb> &vis, int x, int y)
// {
//     return x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && maze[x][y] == '.';
// }

// int bfs(vector<vc> &maze, int xs, int ys,int count)
// {
//     // 记录节点
//     vector<vb> vis(m, vb(n, false));
//     queue<pii> q;
//     q.push(make_pair(xs - 1, ys - 1)); // 插入起点
//     vis[xs - 1][ys - 2] = true;        // 标记起点
//     int steps = 0;

//     while (!q.empty())
//     {
//         int size = q.size();
//         while (size--)
//         {
//             int x = q.front().first;
//             int y = q.front().second;
//             q.pop(); // 获取完节点,进行删除

//             // 检查是否是终点
//             if (maze[x][y] == 'e')
//             {
//                 count++;
//                 return steps;
//             }

//             // 遍历
//             for (int i = 0; i < 4; i++)
//             {
//                 int newX = dx[i] + x;
//                 int newY = dy[i] + y;

//                 // 检查相邻节点
//                 if (isVialid(maze, vis, newX, newY))
//                 {
//                     q.push(make_pair(newX, newY));
//                     vis[newX][newY] = true;
//                 }
//             }
//         }
//         ++steps;
//     }
//     return -1; // 未找到路径
// }

// int main()
// {
//     int xs, ys, t;
//     cin >> m >> n;
//     static int count=0;

//     vector<vc> maze(m, vc(n));
//     for (int i = 0; i < m; i++)
//         for (int j = 0; j < n; j++)
//         {
//             cin >> maze[i][j];
//             if(maze[i][j]=='k')
//                 xs=i,ys=j;
//         }

//     // 调用 BFS 函数求解最短路径并输出结果
//     int shortest_path = bfs(maze, xs, ys,count);
//     cout << count<<" "<<shortest_path << endl;

//     return 0;
// }
