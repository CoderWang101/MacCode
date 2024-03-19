#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int maxLengthOfSubstr(string A, string B, int V)
{
    int n = A.length();
    int maxLength = 0;
    unordered_map<char, int> window;

    for (int i = 0; i < n; i++)
    {
        // 维护窗口大小
        if (i >= n - maxLength)
        {
            break;
        }

        window.clear();
        int diffCount = 0;
        int j = 0;

        // 扩展窗口
        while (j < n && j - i <= maxLength && diffCount <= V)
        {
            if (A[j] != B[j - i])
            {
                diffCount++;
            }

            window[A[j]]++;
            j++;
        }

        // 更新窗口大小
        maxLength = max(maxLength, j - i - 1);

        // 减小窗口
        if (window[A[i]] > 1)
        {
            window[A[i]]--;
        }
        else
        {
            window.erase(A[i]);
        }
    }

    return maxLength;
}

int main()
{
    string A, B;
    int V;

    cin >> A >> B >> V;

    int result = maxLengthOfSubstr(A, B, V);
    cout << result << endl;

    return 0;
}