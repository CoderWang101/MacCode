#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 用邻接矩阵表示图
vector<vector<int> > createGraph(int n) {
    vector<vector<int> > graph(n, vector<int>(n, 0)); // 初始化一个大小为 n*n 的二维数组，初始值为 0

    // 在这里添加您的图的边
    // 例如：graph[i][j] = 1 表示节点 i 和节点 j 之间有一条边
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][0] = 1;
    graph[1][3] = 1;
    graph[2][0] = 1;
    graph[2][3] = 1;
    graph[2][4] = 1;
    graph[3][1] = 1;
    graph[3][2] = 1;
    graph[3][4] = 1;
    graph[4][2] = 1;
    graph[4][3] = 1;

    return graph;
}

// BFS算法
void BFS(vector<vector<int> >& graph, int start) {
    int n = graph.size(); // 获取图的节点数量
    vector<bool> visited(n, false); // 记录节点是否已经访问过
    queue<int> q; // 用于BFS的队列

    visited[start] = true; // 标记起始节点为已访问
    q.push(start); // 将起始节点入队

    while (!q.empty()) {
        int current = q.front(); // 取队首节点
        q.pop(); // 出队
        cout << current << " "; // 输出当前节点

        // 遍历当前节点的所有邻居节点
        for (int i = 0; i < n; ++i) {
            if (graph[current][i] && !visited[i]) 
            {
                 // 如果存在边且邻居节点未被访问过
                visited[i] = true; // 标记该邻居节点为已访问
                q.push(i); // 将邻居节点入队
            }
        }
    }
}

int main() {
    int n = 5; // 图的节点数量
    vector<vector<int> > graph = createGraph(n); // 创建图

    int startNode = 0; // 选择起始节点

    cout << "BFS traversal starting from node " << startNode << ": ";
    BFS(graph, startNode); // 调用BFS算法进行遍历

    return 0;
}