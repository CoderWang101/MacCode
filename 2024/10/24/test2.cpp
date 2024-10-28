#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMinVertex(vector<int>& key, vector<bool>& mstSet, int V) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printMST(vector<int>& parent, vector<vector<int> >& graph, int V) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << char(parent[i] + 'a') << " - " << char(i + 'a') << " \t" << graph[i][parent[i]] << " \n";
    }
}

void primMST(vector<vector<int> >& graph, int V) {
    vector<int> parent(V); 
    vector<int> key(V, INT_MAX); 
    vector<bool> mstSet(V, false);

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = findMinVertex(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);
}

int main() {
    vector<vector<int> > graph(10, vector<int>(10, 0));

    graph[0][1] = 3; graph[0][3] = 5;
    graph[1][0] = 3; graph[1][2] = 5; graph[1][5] = 7;
    graph[2][1] = 5; graph[2][3] = 8; graph[2][4] = 5; graph[2][5] = 5;
    graph[3][0] = 5; graph[3][2] = 8; graph[3][6] = 8;
    graph[4][2] = 5; graph[4][5] = 6; graph[4][7] = 6;
    graph[5][1] = 7; graph[5][2] = 5; graph[5][4] = 6;
    graph[6][3] = 8; graph[6][8] = 4;
    graph[7][4] = 6; graph[7][8] = 1; graph[7][9] = 2;
    graph[8][6] = 4; graph[8][7] = 1; graph[8][9] = 6;
    graph[9][7] = 2; graph[9][8] = 6;

    int V = graph.size();
    primMST(graph, V);

    return 0;
}