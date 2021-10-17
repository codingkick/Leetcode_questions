/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    int dfs(TreeNode *node)
    {
        if(node == NULL)
        {
            return 0;
        }
        int v1 = max(0,dfs(node->left));
        int v2 = max(0,dfs(node->right));
        int sum = v1 + node->val + v2;
        ans = max(ans,sum);
        return node->val + max(v1,v2);
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }
};