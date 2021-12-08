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
    // {sum_of_nodes,tilt_of_nodes}
    vector<int> dfs(TreeNode *node)
    {
        if(node == NULL)
            return {0,0};
        vector<int> v1 = dfs(node->left);
        vector<int> v2 = dfs(node->right);
        return {v1[0]+v2[0]+node->val,abs(v1[0]-v2[0]) + v1[1] + v2[1]};
    }
    int findTilt(TreeNode* root) {
        vector<int> ans = dfs(root);
        return ans[1];
    }
};