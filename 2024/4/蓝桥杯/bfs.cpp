#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int N = 110;
typedef pair<int, int> PII;
int map[N][N], mark[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1},
 n, m, ans;

void bfs()
{
    memset(mark, -1, sizeof(mark));
    queue<PII> q;
    q.push({0, 0});
    mark[0][0] = 0;
    while (!q.empty())
    {
        PII top = q.front();
        for (int i = 0; i < 4; i++)//遍历四个方向
        {
            int nex = top.first + dx[i], 
                ney = top.second + dy[i];

            if (nex >= 0 && nex < n 
                && ney >= 0 && ney < m 
                && mark[nex][ney] == -1 && map[nex][ney] == 0)//已访问-1,未访0;
            {
                mark[nex][ney] = mark[top.first][top.second] + 1;//从起始位置到当前位置的步数
                q.push({nex, ney});
            }
        }  
        q.pop();
    }
    cout << mark[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    bfs();
}