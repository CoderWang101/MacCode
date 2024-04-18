#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param board string字符串vector
     * @param word string字符串
     * @return bool布尔型
     */

    bool dfs(vector<string> &board, string &word, vector<vector<bool> > &ans, int x, int y, int pos) // po当前位置
    {
        // 边界情况 && 不相等
        if (y < 0 || x < 0 || y >= board.size() || x >= board[0].size() || board[y][x] != word[pos] || ans[y][x])
            return false;
        // 边界:访问到最后一个且符合条件
        if (pos == word.size() - 1)
            return true;

        // 标记
        ans[y][x] = true;

        // 方向搜索
        bool found =dfs(board, word, ans, y, x - 1, pos + 1) ||
                    dfs(board, word, ans, y, x + 1, pos + 1) ||
                    dfs(board, word, ans, y - 1, x, pos + 1) ||
                    dfs(board, word, ans, y + 1, x, pos + 1);
        
        // 恢复标记
        ans[y][x] = false;

        return found;
    }

    bool exist(vector<string> &board, string word)
    {
        int szY = board.size(), szX = board[0].size();
        // 标记数组
        vector<vector<bool> > ans(szY, vector<bool>(szX, false));

        for (int i = 0; i < szY; i++)
            for (int j = 0; j < szX; j++)
                if (dfs(board, word, ans, i, j, 0))
                    return true; // 返回true则找到单词
        return false;            // 没找到
    }
};

