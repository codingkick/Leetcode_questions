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
    int res;
    void dfs(TreeNode *node,int num)
    {
        num = num*10 + node->val;
        if(node->left == NULL && node->right == NULL)
        {
            res += num;
            return;
        }
        if(node->left!=NULL)
        dfs(node->left,num);
        if(node->right!=NULL)
        dfs(node->right,num);
    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;
        res = 0;
        dfs(root,0);
        return res;
    }
};