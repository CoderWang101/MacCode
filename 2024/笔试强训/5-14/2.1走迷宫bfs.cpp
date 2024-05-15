#include <iostream>
#include <vector>
using namespace std;
#define vc vector<char>
#define INF 0x3f3f3f3f

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool vis[200][200] = {false};
int m, n;

bool isValid(vector<vc> &maze, int x, int y)
{
    return x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && maze[x][y] == '.';
}

int dfs(vector<vc> &maze, int x, int y)
{
    if (!isValid(maze, x, y))
        return 0;
    vis[x][y] = true;
    int step = 1;
    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (isValid(maze, newX, newY))
            step += dfs(maze, newX, newY);
    
    }
    vis[x][y] = false;

    return step;
}

int main()
{

    int xs, ys, xt, yt;
    cin >> m >> n;
    cin >> xs >> ys >> xt >> yt;

    vector<vc> maze(m, vc(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];

    vector<vector<bool> > vis(m, vector<bool>(n, false));

    int step = INF;
    for (int i = xs - 1; i < m; i++)
    {
        for (int j = ys - 1; j < n; j++)
        {
            if (maze[i][j] == '.' && !vis[i][j])
            {
                int temp = dfs(maze, i, j);
                step = min(temp, step);
            }
        }
    }
    if (step == INF)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << step - 1 << endl;

    return 0;
}