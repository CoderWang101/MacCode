#include <iostream>
using namespace std;

// int main() {
//     int a, b;
//     while (cin >> a >> b) { // 注意 while 处理多个 case
//         cout << a + b << endl;
//     }
// }
// 64 位输出请用 printf("%lld")

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    string s2;
    cin >> s;

    int sz = s.size();

    int i = 0;
    while (i < sz)
    {
        if (i + 1 < sz && s[i] != s[i + 1])
        {
            s2.push_back(s[i]);
        }
        else
        {
            // 处理输出为0的情况
            s2 = "0";
            break;
        }
        i++;
    }

    cout << s2 << endl;

    return 0;
}