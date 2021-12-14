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
    int dfs(TreeNode *node,int l,int h)
    {
        if(node == NULL)
            return 0;
        int sum = 0;
        if(node->val>=l && node->val<=h)
            sum += node->val;
        if(node->val>=h)
        {
            sum += dfs(node->left,l,h);
        }
        else if(node->val<=l)
        {
            sum += dfs(node->right,l,h);
        }
        else
        {
            sum += dfs(node->left,l,h);
            sum += dfs(node->right,l,h);
        }
        return sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return dfs(root,low,high);
    }
};