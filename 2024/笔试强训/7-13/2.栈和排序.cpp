#include <iostream>

#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 栈排序
     * @param a int整型vector 描述入栈顺序
     * @return int整型vector
     */
    vector<int> solve(vector<int> &a)
    {
        vector<int> cope(a);
        sort(cope.begin(), cope.end());
        reverse(cope.begin(), cope.end());
        
        


        int pos = 0, cur = 0;
    }
};