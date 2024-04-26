#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
    //中心扩展算法
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param A string字符串
     * @return int整型
     */

    int getLongestPalindrome(string A)
    {
        int sz=A.size();
                
        if(sz==1)
            return 1;
        else if(sz==0)
            return 0;
        
        int max_len=0;

        int left,right;

        for (int i = 0; i < sz; i++)
        {
            //奇数
            int left=i-1,right=i+1;
            while (left>=0 && right<sz && A[left]==A[right])
                right++,left--;
            max_len=max(max_len,right-left-1);

            //偶数
            left=i-1,right=i;
            while (left>=0 && right<sz && A[left]==A[right])
                right++,left--;
            max_len=max(max_len,right-left-1);
        }
        return max_len;
    }
};