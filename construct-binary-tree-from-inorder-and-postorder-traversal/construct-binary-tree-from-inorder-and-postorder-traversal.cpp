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
    int postind;
    TreeNode* tree(vector<int> &in,vector<int> &post,int l,int r,unordered_map<int,int> &mpp)
    {
        if(l>r)
            return NULL;
        TreeNode *node = new TreeNode();
        node->val = post[postind];
        postind--;
        node->right = tree(in,post,mpp[node->val]+1,r,mpp);
        node->left = tree(in,post,l,mpp[node->val]-1,mpp);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++)
            mpp[inorder[i]] = i;
        postind = n-1;
        return tree(inorder,postorder,0,n-1,mpp);
    }
};