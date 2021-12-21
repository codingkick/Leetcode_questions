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
    int dia(TreeNode* node)
    {
        if(node == NULL)
            return 0;
        int v1 = dia(node->left);
        int v2 = dia(node->right);
        ans = max(ans,v1 + v2);
        return max(v1,v2)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        dia(root);
        return ans;
    }
};