//36%
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int hash[26] = {0};
    string s;
    cin >> s;
    int count = 0, len = s.length();

    // 统计字符出现次数
    for (int i = 0; i < len; i++)
        hash[s[i] - 'a']++;

    int max_count = 0;
    char max_char;

    // 找到哈希表中的最大值
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] > max_count)
        {
            max_count = hash[i];
            max_char = 'a' + i; // 将 ASCII 码转换为字符
        }
    }

    // 计算操作次数
    for (int i = 0; i < len; i++)
    {
        if (s[i] == max_char)
            continue;
        else
        {
            int distance = abs(s[i] - max_char);
            count += min(distance, 26 - distance); // 考虑字母环的情况
        }
    }
    
    cout << count << endl;

    return 0;
}