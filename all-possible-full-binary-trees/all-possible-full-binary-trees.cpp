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
    vector<TreeNode*> func(int n)
    {
        if(n == 1)
        {
            TreeNode *temp = new TreeNode();
            temp->val = 0;
            return {temp};
        }
        vector<TreeNode*> ans;
        for(int i=1;i<=n-2;i++)
        {
            vector<TreeNode*> l = func(i);
            vector<TreeNode*> r = func(n-1-i);
            for(auto it1:l)
            {
                for(auto it2:r)
                {
                    TreeNode *temp = new TreeNode();
                    temp->val = 0;
                    temp->left = it1;
                    temp->right = it2;
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return func(n);
    }
};