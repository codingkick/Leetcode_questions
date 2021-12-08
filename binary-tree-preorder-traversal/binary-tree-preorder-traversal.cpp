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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *ptr = root;
        vector<int> ans;
        while(ptr!=NULL)
        {
            s.push(ptr);
            ans.push_back(ptr->val);
            ptr = ptr->left;
        }
        // while(!s.empty())
        // {
        //     cout<<s.top()->val<<"\n";
        //     s.pop();
        // }
        // cout<<s.size()<<"\n";
        while(!s.empty())
        {
            TreeNode *temp = s.top();
            s.pop();
            // cout<<temp->val<<"<==\n";
            temp = temp->right;
            while(temp!=NULL)
            {
                s.push(temp);
                ans.push_back(temp->val);
                temp = temp->left;
            }
            // cout<<s.size()<<"\n";
        }
        return ans;
    }
};