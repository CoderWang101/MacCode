#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f;

int short_string_len(string &s, int len)
{
    int short_len = INF;
    for (int i = 0; i < len; i++)
    {
        // 奇数
        int left = i, right = i;
        while (left >= 0 && right < len && s[left] == s[right])
        {
            if (right - left + 1 > 1)
                short_len = min(short_len, right - left + 1);
            right++, left--;
        }

        // 偶数
        left = i, right = i + 1;
        while (left >= 0 && right < len && s[left] == s[right])
        {
            if (right - left + 1 > 1)
                short_len = min(short_len, right - left + 1);
            right++, left--;
        }
    }
    return short_len;
}

int main()
{
    string s;
    cin >> s;

    int len = s.length();
    if (len <= 1)
    {
        cout << -1 << endl;
        return 0;
    }
    int short_len = short_string_len(s, len);
    cout << short_len << endl;

    return 0;
}
