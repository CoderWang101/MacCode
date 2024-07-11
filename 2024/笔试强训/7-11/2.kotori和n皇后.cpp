//40%
// 对角线可以用[x-y]、[x+y]来表示所在对角线
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

#define pii pair<int, int>

using namespace std;

int main()
{
    int k;
    cin >> k;

    // 存储皇后坐标
    vector<pii> q(k);
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        q[i] = make_pair(x, y);
    }

    unordered_map<int, int> row_count, col_count;    // 横竖
    unordered_map<int, int> diagonal45, diagonal135; // 对角线

    // 计算波及行列及对角线
    for (auto queue : q)
    {
        int x = queue.first;
        int y = queue.second;

        row_count[x]++;
        col_count[x]++;
        diagonal45[x - y]++;
        diagonal135[x + y]++;
    }

    // 询问次数
    int n;
    cin >> n;

    // 判读是否被命中
    vector<bool> results(n);
    for (int i = 0; i < n; ++i)
    {
        int query_index;
        cin >> query_index;
        query_index--; // 转换为0-based索引

        int x = q[query_index].first;
        int y = q[query_index].second;

        // 判断是否存在攻击情况
        if (row_count[x] > 1 || col_count[y] > 1 || diagonal45[x - y] > 1 || diagonal135[x + y] > 1)
            results[i] = true;
        else
            results[i] = false;
    }

    // 输出结果
    for (bool result : results)
    {
        cout << (result ? "Yes" : "No") << endl;
    }

    return 0;
}
