#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

#define INF 0x3f3f3f3f

int min_distance(vector<string> &strs, string &str1, string &str2)
{
    int mind = INF;
    int id1 = -1, id2 = -1;

    for (int i = 0; i < strs.size(); ++i)
    {
        if (strs[i].compare(str1) == 0) // 使用 compare 函数来比较字符串是否相等
            id1 = i;
        if (strs[i].compare(str2) == 0)
            id2 = i;

        if (id1 != -1 && id2 != -1)
        {
            int current_distance = abs(id2 - id1);
            mind = min(mind, current_distance); // 使用 min 函数更新最小距离
        }
    }

    // 在循环结束后检查 id1 和 id2 是否有效
    if (id1 == -1 || id2 == -1)
        return -1;

    return mind;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    if (n == 0)
        return -1;

    string str1, str2;
    cin >> str1 >> str2;

    vector<string> strs(n);
    for (int i = 0; i < n; i++)
        cin >> strs[i];

    cout << min_distance(strs, str1, str2) << endl;

    return 0;
}


//通过率40%
// #include <iostream>
// #include<vector>
// #include<string>
// #include <cmath>
// using namespace std;

// #define INF 0x3f3f3f3f

// int min_distance(vector<string> &strs, string &str1, string &str2)
// {
//     // 最短距离
//     int mind = INF;

//     // 记录位置
//     int id1 = -1, id2 = -1;

//     // 找相同字符
//     for (int i = 0; i < strs.size(); ++i)
//     {
//         // 进行字符串比较
//         if (strs[i] == str1) // strs[i]:字符; str1:字符串
//         {
//             id1 = i;
//         }
//         if (strs[i] == str2)
//         {
//             id2 = i;
//         }

//         // 最小距离
//         if (id1 != -1 && id2 != -1)
//             mind = (mind, abs(id2 - id1));

//         if (id1==-1 || id2==-1)
//             return -1;
//     }
//     return mind;
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int a, b, n;
//     cin >> n;
//     if (n == 0)
//         return -1;
//     string str1, str2;
//     cin >> str1 >> str2;

//     vector<string> strs(n);
//     for (int i = 0; i < n; i++)
//         cin >> strs[i];

//     cout << min_distance(strs, str1, str2) << endl;

//     return 0;
// }
