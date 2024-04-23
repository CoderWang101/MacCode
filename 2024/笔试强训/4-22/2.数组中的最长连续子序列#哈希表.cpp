#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//利用哈希表完成
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * max increasing subsequence
     * @param arr int整型vector the array
     * @return int整型
     */
    int MLS(vector<int> &arr)
    {
        int sz = arr.size();
        if (sz == 0)
            return 0; // 处理数组为空的情况

        unordered_map<int, bool> exist;
        for (int num : arr)
        {
            exist[num] = true;
        }

        int maxLen = 0;
        for (int num : arr)
        {
            if (!exist.count(num - 1)) // 判断是否为连续序列的起点
            {
                int curLen = 1;
                while (exist.count(num + 1)) // 向后查找连续序列的长度
                {
                    curLen++;
                    num++;
                }
                maxLen = max(maxLen, curLen);
            }
        }

        return maxLen;
    }
};

// int main() {
//     Solution solution;
//     vector<int> arr = {1, 3, 5, 2, 4, 6, 8};
//     cout << solution.MLS(arr) << endl; // Output should be 4
//     return 0;
// }