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
    pair<int,int> dfs(TreeNode *node)
    {
        if(node == NULL)
            return {0,0};
        pair<int,int> v1 = dfs(node->left);
        pair<int,int> v2 = dfs(node->right);
        // {nahi liya,liya}
        return {max(v1.first,v1.second) + max(v2.first,v2.second),node->val + v1.first + v2.first};
    }
    int rob(TreeNode* root) {
        pair<int,int> val = dfs(root);
        return max(val.first,val.second);
    }
};