//100%
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define PII pair<int, int>

bool compare(const PII &a, const PII &b)
{
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;

    vector<PII> activities(n);
    for (int i = 0; i < n; i++)
        cin >> activities[i].first >> activities[i].second;

    // 按照结束时间排序
    sort(activities.begin(), activities.end(), compare);

    int count = 1;
    int end_time = activities[0].second;

    for (int i = 1; i < n; i++)
    {
        if (activities[i].first >= end_time)
        {
            ++count,
            end_time = activities[i].second;
        }
    }

    cout << count << endl;

    return 0;
}

//50%
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// #define PII pair<int, int>

// int main()
// {
//     int n;
//     cin >> n;

//     vector<PII> active(n);
//     for (int i = 0; i < n; i++)
//         cin >> active[i].first >> active[i].second;
//     //按开始时间排序
//     sort(active.begin(), active.end());

//     // 计算不重叠活动数量
//     int count = 1, end_time = active[0].second;
//     for (int i = 1; i < n; i++)
//     {
//         if (active[i].first >= end_time)
//         {
//             ++count;
//             end_time = active[i].second;
//         }
//     }

//     cout << count << endl;

//     return 0;
// }