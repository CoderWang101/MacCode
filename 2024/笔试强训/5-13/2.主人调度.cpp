#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
#define INF 0x3f3f3f3f
#define  VI vector<int>
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param schedule int整型vector<vector<>>
     * @return bool布尔型
     */

    static bool compareByEndTime(const vector<VI> &a, const vector<VI> &b)
    {
        return a[0][1] <= b[0][1];
    } 

    bool hostschedule(vector<VI> &schedule)
    {
        sort(schedule.begin(), schedule.end(), compareByEndTime);

        int sz=schedule.size();
        int end_time=-1,hostcount=0;

        for (int i = 0; i < sz; i++)
        {
            if(schedule[i][0]>=end_time)
            {
                end_time=schedule[i][1];
                ++hostcount;
            }
        }
        if(hostcount<=1)
            return true;
        return false;
    }
};