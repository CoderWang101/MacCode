//题解
#include <iostream>
using namespace std;
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
    bool hostschedule(vector<VI> &schedule)
    {
        //按照vector左端点进行排序
        sort(schedule.begin(), schedule.end());
        //sort(schedule.begin(), schedule.end(), compareByEndTime);

        for (int i = 1; i < schedule.size(); i++)
            if(schedule[i][0]<schedule[i-1][1])
                return false;         

        return true;
    }
};