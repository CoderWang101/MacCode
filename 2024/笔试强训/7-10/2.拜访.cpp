#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int countPath(vector<vector<int> >& CityMap, int n, int m) {
        // 定义四个方向的移动向量：右、左、下、上
        vector<pair<int, int> > directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        // 找到经理位置（1）和商店位置（2）
        pair<int, int> start, end;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (CityMap[i][j] == 1)
                    start = {i, j};
                else if (CityMap[i][j] == 2)
                    end = {i, j};
            }
        }
        
        // BFS 初始化
        queue<pair<int, int>> q;
        q.push(start);
        
        // 用于记录到每个位置的最短路径数量的数组
        vector<vector<int>> countPaths(n, vector<int>(m, 0));
        countPaths[start.first][start.second] = 1; // 从经理位置开始有一条路径
        
        // BFS 循环
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            
            // 探索当前位置的相邻位置
            for (auto& dir : directions) {
                int ni = current.first + dir.first;
                int nj = current.second + dir.second;
                
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && CityMap[ni][nj] != -1) {
                    if (countPaths[ni][nj] == 0) {
                        // 第一次访问该相邻位置
                        countPaths[ni][nj] = countPaths[current.first][current.second];
                        q.push({ni, nj});
                    } else {
                        // 已经访问过该相邻位置，累加路径数量
                        countPaths[ni][nj] += countPaths[current.first][current.second];
                    }
                }
            }
        }
        
        return countPaths[end.first][end.second];
    }
};


// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <queue>
// using namespace std;

// #define VI vector<int>
// #define VB vector<bool>
// #define pii pair<int,int>

// // 方向数组，用于计算相邻节点的坐标变化
// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};

// class Solution
// {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      *
//      * @param CityMap int整型vector<vector<>>
//      * @param n int整型
//      * @param m int整型
//      * @return int整型
//      */
//     // 检查节点是否合法
//     bool isValid(vector<VI> &maze, vector<VB> &vis, int x, int y)
//     {
//         return x >= 0 && x < maze[0].size() && y >= 0 && y < maze.size() && !vis[x][y] && maze[x][y] != -1;
//     }

//     int bfs(vector<VI> &CityMap, int ps, int py)
//     {
//         vector<VB> vis(CityMap[0].size(),VB( CityMap.size(),false));
//         queue<pii> q;
//         q.push(make_pair(xs-1,ys-1));


//     }

//     int countPath(vector<VI> &CityMap, int n, int m)
//     {
//         if (n >= 10 || m >= 10)
//             return 0;

//         for (int i = 0; i < m; i++)
//             for (int j = 0; j < n; j++)
//                 cin >> CityMap[i][j];

//         // 找到经理
//         int pos_x = 0, pos_y = 0;
//         for (int i = 0; i < m; i++)
//             for (int j = 0; j < n; j++)
//                 if (CityMap[i][j] == 1)
//                     pos_x = i, pos_y = j;

//         int shortest_path = bfs(CityMap, pos_x, pos_y);
//         cout << shortest_path << endl;

//         return 0;
//     }
// };