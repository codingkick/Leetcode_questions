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
    int diameter;
    int dia(TreeNode *node)
    {
        if(node == NULL)
            return 0;
        int v1 = dia(node->left);
        int v2 = dia(node->right);
        int temp = v1 + v2;
        diameter = max(diameter,temp);
        return max(v1,v2) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        dia(root);
        return diameter;
    }
};