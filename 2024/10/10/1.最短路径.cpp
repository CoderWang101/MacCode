// #include <iostream>
// #include <vector>
// #include <queue>
// #include <algorithm> // For reverse

// using namespace std;

// typedef vector<int> vi;

// void BFS(const vector<vi>& graph, int start, int end) {
//     vector<bool> visited(graph.size(), false);
//     vector<int> parent(graph.size(), -1);
//     queue<int> q;
    
//     q.push(start);
//     visited[start] = true;

//     while (!q.empty()) {
//         int node = q.front();
//         q.pop();

//         if (node == end) break;

//         for (int i = 0; i < graph[node].size(); ++i) {
//             if (graph[node][i] != 0 && !visited[i]) {
//                 q.push(i);
//                 visited[i] = true;
//                 parent[i] = node;
//             }
//         }
//     }

//     if (!visited[end]) {
//         cout << "No path found" << endl;
//         return;
//     }

//     vector<int> path;
//     for (int at = end; at != -1; at = parent[at])
//         path.push_back(at);

//     reverse(path.begin(), path.end());

//     cout << "Shortest path from V1 to V6: ";
//     for (int v : path) {
//         cout << "V" << v + 1;
//         if (v != end) cout << " -> ";
//     }
//     cout << endl;
// }

// int main() {
//     vector<vi> maze;
    
//     maze.push_back({0, 1, 0, 0, 0, 1});
//     maze.push_back({0, 0, 1, 0, 0, 0});
//     maze.push_back({1, 0, 0, 1, 0, 0});
//     maze.push_back({0, 0, 0, 0, 0, 0});
//     maze.push_back({0, 0, 1, 1, 0, 0});
//     maze.push_back({0, 0, 1, 0, 1, 0});

//     BFS(maze, 0, 5); // 从 V1 (索引0) 到 V6 (索引5)
//     return 0;
// }