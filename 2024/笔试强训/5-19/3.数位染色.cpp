#include <iostream>
#include <string>
#include <vector>
using namespace std;
//42%%
int main()
{
    // 优化输入输出性能
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    vector<int> a(s.size());
    int sum = 0;

    // 将字符转换为数字，并计算总和
    for (int i = 0; i < s.size(); i++)
    {
        a[i] = s[i] - '0';
        sum += a[i];
    }

    int left = 0, right = 0, gather = a[0]; // 初始化gather为第一个数字
    while (right < a.size())
    {
        if (gather == sum)
        {
            cout << "Yes" << endl;
            return 0;
        }

        if (gather < sum && right + 1 < a.size())
        {
            right++;
            gather += a[right];
        }
        else
        {
            gather -= a[left];
            left++;
        }
    }

    cout << "No" << endl;

    return 0;
}