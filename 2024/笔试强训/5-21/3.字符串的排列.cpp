// 回溯 91.67%
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> Permutation(string str)
    {
        vector<string> result;

        if (str.empty())
            return result;

        backtrack(str, 0, result);

        return result;
    }

private:
    void backtrack(string &str, int start, vector<string> &result)
    {
        // 到达最后一个字符
        if (start == str.length() - 1)
        {
            result.push_back(str); // 将当前排列加入结果中
            return;
        }

        for (int i = start; i < str.length(); ++i)
        {
            if (i != start && str[i] == str[start])
                continue; // 避免重复排列

            swap(str[i], str[start]);          // 交换字符位置
            backtrack(str, start + 1, result); // 递归生成下一个字符位置的排列
            swap(str[i], str[start]);          // 恢复原始状态，进行下一次交换
        }
    }
};

// //暴力 41.67%
// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// class Solution
// {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      *
//      * @param str string字符串
//      * @return string字符串vector
//      */
//     vector<string> Permutation(string str)
//     {
//         vector<string> all;

//         all.push_back(str);

//         int pos = 0, cur = 1;
//         while (pos < str.length())
//         {
//             if (cur == str.length() || pos + 1 >= str.length())
//             {
//                 ++pos;
//                 cur = pos + 1;
//             }
//             else if (pos + 1 == str.length())
//                 break;

//             string tmp = str;
//             if (str[pos] != str[cur])
//             {
//                 swap(tmp[pos], tmp[cur]);
//                 all.push_back(tmp);
//             }

//             ++cur;

//             if (cur == str.length())
//             {
//                 ++pos;
//                 cur = pos + 1;
//             }
//         }
//         return all;
//     }
// };