// #include <iostream>
// #include <vector>
// #include <climits>

// using namespace std;

// // 定义图的顶点数
// #define V 9

// int minKey(int key[], bool mstSet[])
// {
//     // 初始化为无穷大的最小值
//     int min = INT_MAX, min_index;

//     for (int v = 0; v < V; v++)
//         if (!mstSet[v] && key[v] < min)
//             min = key[v], min_index = v;

//     return min_index;
// }

// void printMST(int parent[], int graph[V][V])
// {
//     char x='A';
//     cout << "路径 \t 权重\t\n";
//     for (int i = 1; i < V; i++)
//         cout << char(x+parent[i]) << " - " <<char(x+ i) << " \t" << graph[i][parent[i]] << " \n";
// }

// void primMST(int graph[V][V])
// {
//     // 存储构建的 MST
//     int parent[V];
//     // 用于找最小权值边
//     int key[V];
//     // 表示是否包含在 MST 中的顶点集合
//     bool mstSet[V];

//     // 初始化所有的键值为无穷大
//     for (int i = 0; i < V; i++)
//         key[i] = INT_MAX, mstSet[i] = false;

//     // 选择第一个顶点作为 MST 的起点
//     key[0] = 0;
//     parent[0] = -1;

//     // 构建 MST
//     for (int count = 0; count < V - 1; count++)
//     {
//         int u = minKey(key, mstSet);

//         mstSet[u] = true;

//         for (int v = 0; v < V; v++)
//             if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
//                 parent[v] = u, key[v] = graph[u][v];
//     }

//     printMST(parent, graph);
// }

// int main()
// {
//     /* 示例图： */
//     int graph[V][V] = {
//     //   A  B  C  D  E  F  G  H  I
//         {0, 2, 0, 1, 0, 0, 0, 0, 0},
//         {2, 0, 6, 3, 0, 0, 0, 0, 0},
//         {0, 6, 0, 0, 2, 0, 0, 0, 0},
//         {1, 3, 0, 0, 9, 0, 0, 0, 6},
//         {0, 0, 2, 9, 0, 7, 0, 4, 0},
//         {0, 0, 0, 0, 7, 0, 1, 0, 5},
//         {0, 0, 0, 0, 0, 1, 0, 5, 1},
//         {0, 0, 0, 0, 4, 0, 5, 0, 0},
//         {0, 0, 0, 6, 0, 5, 1, 0, 0}};

//     primMST(graph);

//     return 0;
// }