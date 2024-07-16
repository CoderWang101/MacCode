//100%
#include <iostream>
#include <vector>
#include <iomanip> // 添加这个头文件用于设置输出格式
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    if (m == n)
    {
        cout << fixed << setprecision(2) << 1.00 << " " << 5.00 << endl;
        return 0;
    }

    vector<int> v(n - m);
    for (int i = 0; i < n - m; i++)
        cin >> v[i];

    int count = 0;
    for (int i = 0; i < n - m; i++)
        count += v[i];

    double min = 0.0, max = 0.0;

    min = (double)(count + m) / (double)n;     // 最小平均值
    max = (double)(count + 5 * m) / (double)n; // 最大平均值

    // 使用 fixed 和 setprecision 设置输出格式
    cout << fixed << setprecision(5) << min << " " << max << endl;//setprecision:设置小数点后精位

    return 0;
}