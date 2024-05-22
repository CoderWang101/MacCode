#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstringTwoDistinct(string s)
{
    int n = s.length();
    if (n < 3)
        return n;

    unordered_map<char, int> map;
    int left = 0, right = 0;
    int maxLen = 2;

    while (right < n)
    {
        if (map.size() <= 2)
        {
            map[s[right]] = right;
            ++right;
        }

        if (map.size() > 2)
        {
            int leftmost = n;
            for (auto &pair : map)
                leftmost = min(leftmost, pair.second);
                
            map.erase(s[leftmost]);
            left = leftmost + 1;
        }

        maxLen = max(maxLen, right - left);
    }

    return maxLen;
}

int main()
{
    string s;
    cin >> s;
    cout << lengthOfLongestSubstringTwoDistinct(s) << endl;
    return 0;
}

// #include <iostream>
// #include<string>
// #include<queue>
// #include<algorithm>
// using namespace std;

// #define PCC pair<char,char>

// int main()
// {
//     string s;
//     cin>>s;
//     PCC num;
//     int len=s.length();
//     int left=0,right=1;
//     num=make_pair(s[0],s[1]);
//     int count=0;
//     while (right<len)
//     {
//         if(num.first==num.second)
//         {
//             ++right;
//             num.second=s[right];
//         }
//         count=max(count,right-left+1);

//         //遇到第三个不同元素
//         if(num.first!=num.second && num.second!=s[right])
//         {
//             ++right;
//             num.second=s[right];
//             while(num.first==s[left])
//             {
//                 ++left;
//                 num.first=s[left];
//                 if(num.first!=s[left])
//                 {
//                     num.first=s[left];
//                     break;
//                 }
//             }
//         }
//     }
//     cout<<count<<endl;

//     return 0;
// }
