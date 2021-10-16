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
    void inorder(TreeNode *node,vector<int> &ans)
    {
        stack<TreeNode*> s;
        TreeNode *ptr = node;
        while(ptr!=NULL)
        {
            s.push(ptr);
            ptr = ptr->left;
        }
        while(!s.empty())
        {
            TreeNode *temp = s.top();
            s.pop();
            ans.push_back(temp->val);
            ptr = temp->right;
            while(ptr!=NULL)
            {
                s.push(ptr);
                ptr = ptr->left;
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL)
            return {};
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
};