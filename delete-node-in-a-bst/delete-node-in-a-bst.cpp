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
    TreeNode* dfs(TreeNode *node,int key)
    {
        if(node == NULL)
            return NULL;
        if(node->val > key)
        {
            node->left = dfs(node->left,key);
            return node;
        }
        else if(node->val<key)
        {
            node->right = dfs(node->right,key);
            return node;
        }
        else
        {
            if(node->left == NULL && node->right == NULL)
                return NULL;
            else if(node->left!=NULL && node->right == NULL)
            {
                return node->left;
            }
            else if(node->left==NULL && node->right != NULL)
            {
                return node->right;
            }
            else
            {
                TreeNode *temp = node->right,*last = node,*sec_last = NULL;
                while(temp!=NULL)
                {
                    sec_last = last;
                    last = temp;
                    temp = temp->left;
                }
                if(last->right == NULL)
                {
                    if(sec_last == node)
                        sec_last->right = NULL;
                    else
                        sec_last->left = NULL;
                    node->val = last->val;
                }
                else
                {
                    if(sec_last == node)
                    {
                        node->val = last->val;
                        sec_last->right = last->right;
                    }
                    else
                    {
                        sec_last->left = last->right;
                        node->val = last->val;
                    }
                }
                return node;
            }
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return NULL;
        return dfs(root,key);
    }
};