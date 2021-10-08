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
            return {0,0,10000};
        vector<int> v1 = dfs(node->left);
        vector<int> v2 = dfs(node->right);
        int r0 = v1[1] + v2[1];
        int r1 = min(v1[2] + min(v2[1],v2[2]),v2[2] + min(v1[1],v1[2]));
        int r2 = 1 + min({v1[0],v1[1],v1[2]}) + min({v2[0],v2[1],v2[2]});
        return {r0,r1,r2};
    }
    int minCameraCover(TreeNode* root) {
        vector<int> ans = dfs(root);
        return min({ans[1],ans[2]});
    }
};