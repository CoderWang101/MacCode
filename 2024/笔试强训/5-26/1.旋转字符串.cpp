//75%
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 旋转字符串
     * @param A string字符串
     * @param B string字符串
     * @return bool布尔型
     */
    bool solve(string A, string B)
    {
        if(B.length()==0)
            return true;

        string tmp=A;
        A+=tmp;
        int pos_a=0,pos_B=0,cur=0;
        
        while (pos_a<A.length())
        {
            cur=pos_a;
            while(A[cur]==B[pos_B])
            {
                ++pos_B,++cur;
                if(pos_B==B.length()-1)
                    return true;
            }
            //不符合重置
            pos_B=0;
            ++pos_a;
        }
        
        return false;
    }
};