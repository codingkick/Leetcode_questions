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
    TreeNode* proc(TreeNode *node)
    {
        if(node == NULL)
            return NULL;
        TreeNode *l = node->left,*r = node->right,*t1 = NULL,*t2 = NULL;
        if(l!=NULL)
        {
            t1 = proc(l);
            node->right = l;
            node->left = NULL;
            t1->right = r;
        }
        if(r!=NULL)
        {
            t2 = proc(r);
            return t2;
        }
        else
        {
            if(l!=NULL)
                return t1;
            else
                return node;
        }
    }
    void flatten(TreeNode* root) {
        proc(root);
    }
};