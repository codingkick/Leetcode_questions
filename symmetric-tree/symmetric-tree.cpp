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
    bool ismirror(TreeNode *node1,TreeNode *node2)
    {
        if(node1 == NULL && node2==NULL)
            return true;
        if(node1 == NULL && node2!=NULL)
            return false;
        if(node1 != NULL && node2==NULL)
            return false;
        bool v1 = ismirror(node1->left,node2->right);
        bool v2 = ismirror(node1->right,node2->left);
        if(v1==true && v2 == true && node1->val == node2->val)
            return true;
        else
            return false;
    }
    bool isSymmetric(TreeNode* root) {
        return ismirror(root->left,root->right);
    }
};