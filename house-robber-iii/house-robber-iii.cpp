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
    vector<int> dfs(TreeNode *node)
    {
        if(node == NULL)
            return {0,0};
        vector<int> v1 = dfs(node->left);
        vector<int> v2 = dfs(node->right);
//         [le ke,bina liye]
        int leke = node->val + v1[1] + v2[1];
        int binaliye = max(v1[0],v1[1]) + max(v2[0],v2[1]);
        return {leke,binaliye};
    }
    int rob(TreeNode* root) {
        vector<int> ans = dfs(root);
        return max(ans[0],ans[1]);
    }
};