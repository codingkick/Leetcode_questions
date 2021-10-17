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
    string intostr(int n)
    {
        string ret = "";
        if(n == 0)
        {
            ret += '0';
            return ret;
        }
        bool neg = false;
        if(n<0)
            neg = true;
        n = abs(n);
        while(n>0)
        {
            char temp = (n%10) +'0';
            ret = temp + ret;
            n = n/10;
        }
        if(neg == true)
            return '-'+ret;
        return ret;
    }
    string func(TreeNode *node,set<TreeNode*> &ans,unordered_map<string,TreeNode*> &mpp)
    {
        if(node == NULL)
        {
            string ret = "";
            ret += '#';
            return ret;
        }
        string ins = intostr(node->val) + ',' + func(node->left,ans,mpp) + ',' + func(node->right,ans,mpp);
        // cout<<ins<<"\n";
        if(mpp.find(ins) != mpp.end())
        {
            ans.insert(mpp[ins]);
        }
        else
        {
            mpp[ins] = node;
        }
        return ins;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,TreeNode*> mpp;
        set<TreeNode*> ans;
        func(root,ans,mpp);
        vector<TreeNode*> res;
        for(auto it:ans)
            res.push_back(it);
        return res;
    }
};