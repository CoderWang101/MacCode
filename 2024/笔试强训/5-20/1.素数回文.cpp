// 30%
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
#define INF 0x3f3f3f3f

// 判断是否是质数
bool isPrime(int n)
{
    if (n <= 1)
        return false; // 确保大于1

    int sqrtN = sqrt(n); // 计算n的平方根

    for (int i = 2; i <= sqrtN; i++)
        if (n % i == 0)
            return false; // 如果能整除，则不是质数

    return true; // 如果不能整除，则是质数
}

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    string tmp = s;

    if (len % 2 != 0)
        tmp.pop_back();

    for (int i = s.size() - 1; i >= 0; --i)
        tmp += s[i];
    s += tmp;

    int number = stoi(s);
    if (!isPrime(number))
        cout << "prime" << endl;
    else
        cout << "noprime" << endl;

    return 0;
}