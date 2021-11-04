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
    int sum;
    void dfs(TreeNode *node,bool isleft)
    {
        if(node == NULL)
            return;
        if(node->left == NULL && node->right == NULL && isleft == true)
        {
            sum += node->val;
            return;
        }
        if(node->left != NULL)
            dfs(node->left,true);
        if(node->right != NULL)
            dfs(node->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        sum = 0;
        dfs(root,false);
        return sum;
    }
};