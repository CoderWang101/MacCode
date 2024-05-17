#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型
     */

    int ret = -1010;

    int dfs(TreeNode *node)
    {
        if (node == nullptr)
            return 0;

        int l = max(0,dfs(node->left));  // 左子树的最大单链和
        int r = max(0,dfs(node->right)); // 右子树的最大单链和

        ret=max(ret,node->val+l+r);

        return node->val+max(l,r);//向上返回
    }

    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        return ret;
    }
}; 