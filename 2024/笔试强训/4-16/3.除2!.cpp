#include <iostream>
#include <queue>
using namespace std;

#define int long long

signed main()
{
    // 创建优先级队列
    priority_queue<int, vector<int>, less<int>> pq;

    int k, n;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    int sum = 0;

    while (!pq.empty())
    {
        int top_element = pq.top();
        if (k > 0 && top_element % 2 == 0)
        {
            int tmp = top_element / 2;
            sum += tmp;
            k--;
            // 若相除后依旧是偶数->继续进堆
            if (tmp %=2 == 0)
                pq.push(tmp);
        }
        else
            sum += top_element;
        pq.pop();
    }

    cout << sum << endl;

    return 0;
}
