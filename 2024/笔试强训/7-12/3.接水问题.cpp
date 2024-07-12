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
     * max water
     * @param arr int整型vector the array
     * @return long长整型
     */
    long long maxWater(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return 0;

        vector<int> left_max(n);
        vector<int> right_max(n);
        int total_water = 0;

        // Fill left_max array
        left_max[0] = arr[0];
        for (int i = 1; i < n; i++)
            left_max[i] = max(left_max[i - 1], arr[i]);

        // Fill right_max array
        right_max[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            right_max[i] = max(right_max[i + 1], arr[i]);

        // Calculate total water
        for (int i = 0; i < n; i++)
            total_water += min(left_max[i], right_max[i]) - arr[i];

        return total_water;
    }
};