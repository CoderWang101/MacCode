//100%
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
#define INF 0x3f3f3f3f

bool isPrime(int n)
{
    if (n <= 1)
        return false; // 确保大于1

    int sqrtN = sqrt(n); // 计算n的平方根

    for (int i = 2; i <= sqrtN; i++)
    {
        if (n % i == 0)
        {
            return false; // 如果能整除，则不是质数
        }
    }

    return true; // 如果不能整除，则是质数
}

int main()
{
    string word;
    cin >> word;

    int hash[125] = {0};

    for (int i = 0; i < word.size(); i++)
    {
        char tmp = word[i];
        if (tmp >= 'A' && tmp <= 'Z')
            tmp += 32;
        hash[tmp]++;
    }

    int max_count = 0, min_count = INF;
    for (int i = 'a'; i <= 'z'; i++)
    {
        max_count = max(max_count, hash[i]);
        if (hash[i] > 0)
            min_count = min(min_count, hash[i]);
    }

    int d = max_count - min_count;
    if (isPrime(d))
    {
        cout << "Lucky Word" << endl;
        cout << d << endl;
    }
    else
    {
        cout << "No Answer" << endl;
        cout << 0 << endl;
    }

    return 0;
}