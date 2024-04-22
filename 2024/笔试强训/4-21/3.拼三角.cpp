#include <iostream>
#include <vector>
#include <algorithm> // 添加这行以使用 sort() 函数
using namespace std;

void solve()
{
    vector<int> num;
    int sum = 0;
    for (int i = 0; i < 6; i++)
    {
        int tmp = 0;
        cin >> tmp;

        // 检查输入是否为负数
        if (tmp < 0)
            return; // 如果输入为负数，则退出 solve() 函数

        num.push_back(tmp);
        sum += tmp;
    }

    sort(num.begin(), num.end());

    // 检查是否可能构成两个三角形
    if (2 * num[0] < sum)
    {
        // 检查第一个三角形的边长条件
        if (num[2] < num[0] + num[1])
        {
            // 检查第二个三角形的边长条件
            if (num[5] < num[4] + num[3])
            {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        solve();
    }
    return 0;
}