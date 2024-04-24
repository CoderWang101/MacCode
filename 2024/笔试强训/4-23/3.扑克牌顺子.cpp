#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return bool布尔型
     */

    bool IsContinuous(vector<int> &numbers)
    {
        if (numbers.empty())
            return false;

        int zeroCount = 0;
        int gapCount = 0;
        int n = numbers.size();

        // 统计0的个数
        for (auto num : numbers)
            if (num == 0)
                zeroCount++;

        sort(numbers.begin(), numbers.end());

        // 统计间隔数
        for (int i = zeroCount; i < n - 1; i++)
        {
            if (numbers[i] == numbers[i + 1]) 
                return false;
            gapCount += numbers[i + 1] - numbers[i] - 1;
        }
        return gapCount <= zeroCount; 
    }
};