#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool vis[200][200] = {false};
    int m, n;

    //检查是否有被搜索
    bool isValid(int x, int y, vector<vector<char> >& grid)
    {
        return x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] == '1';
    }

    int dfs(vector<vector<char> >& grid, int x, int y)
    {
        if (!isValid(x, y, grid))
            return 0;

        vis[x][y] = true;
        int found = 1;

        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            found += dfs(grid, newX, newY);
        }

        return found;
    }

    int solve(vector<vector<char> >& grid)
    {
        m = grid.size();
        n = grid[0].size();
        int islands = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }

        return islands;
    }
};

// #include <iostream>
// #include <vector>
// using namespace std;
// class Solution
// {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      * 判断岛屿数量
//      * @param grid char字符型vector<vector<>>
//      * @return int整型
//      */
//     int dx[4] = {1, -1, 0, 0};
//     int dy[4] = {0, 0, 1, -1};
//     bool vis[1001][1001] = {false};
//     int m, n;

//     int dfs(vector<vector<char> > &grid,int x,int y,int pos)
//     {
//         //边界情况
//         if(y>0||y<=grid[0].size()||x>0||x<=grid.size()||!vis[x][y]||grid[x][y]==0)
//             return 0;
//         if (pos==grid.size()-1)
//             return 0;

//         vis[x][y]=true;
//         int found=0;
//         for (int i = 0; i < 4; i++)
//         {
//             found=1+dfs(grid,x+dx[i],y+dy[i],pos+1);
//         }
//         vis[x][y]=false;
//         return found;
//     }

//     int solve(vector<vector<char> > &grid)
//     {
//         m=grid.size(),n=grid[0].size();

//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 dfs(grid,i,j,0);
//             }
            
//         }
        
//     }
// };