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
    void postorder(TreeNode *node,vector<int> &ans)
    {
        stack<TreeNode*> s;
        TreeNode *ptr = node;
        while(ptr!=NULL)
        {
            ans.push_back(ptr->val);
            s.push(ptr);
            ptr = ptr->right;
        }
        while(!s.empty())
        {
            TreeNode *temp = s.top();
            s.pop();
            ptr = temp->left;
            while(ptr!=NULL)
            {
                ans.push_back(ptr->val);
                s.push(ptr);
                ptr = ptr->right;
            }
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};