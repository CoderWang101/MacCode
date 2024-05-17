//100%
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int q;
    cin >> q;

    while (q--)
    {
        int a;
        cin >> a;

        // 如果输入的数字已经是偶数，则直接输出
        if (a % 2 == 0)
        {
            cout << a << endl;
            continue;
        }

        string s = to_string(a);
        int sz = s.size();

        // 从右向左找到第一个偶数，并将其与最后一个数字交换
        for (int i = sz - 1; i >= 0; --i)
        {
            if ((s[i] - '0') % 2 == 0)
            {
                swap(s[i], s[sz - 1]);
                break;
            }
        }

        // 如果没有找到偶数，则输出-1
        if ((s[sz - 1] - '0') % 2 != 0)
        {
            cout << -1 << endl;
            continue;
        }

        // 输出重排后的数字
        cout << s << endl;
    }

    return 0;
}
// #include <iostream>
// #include<string>
// using namespace std;

// int main()
// {
//     int q;
//     cin >> q;
//     while (q--)
//     {
//         int a;
//         cin >> a;

//         if (a % 2 == 0)
//         {
//             cout << a << endl;
//             continue;
//         }

//         string s=to_string(a);
//         int sz=s.size();

//         for (int i = sz-1; i >= 0; --i)
//         {
//             if((s[i]-'0')%2==0)
//             {
//                 swap(s[sz-1],s[i]);
//                 break;
//             }
//         }
        
//         if((s[sz-1]-'0')%2!=0)
//         {
//             cout<<-1<<endl;
//             continue;
//         }

//         cout<<s<<endl;
//     }

//     return 0;
// }
