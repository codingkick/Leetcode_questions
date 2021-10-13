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
    pair<TreeNode*,int> build(vector<int>& in, vector<int>& post,int postind,unordered_map<int,int> &mpp,int l,int r)
    {
        if(postind<0)
            return {NULL,postind};
        if(l>r)
            return {NULL,postind};
        TreeNode *new_node = new TreeNode();
        new_node->val = post[postind];
        postind--;
        int ind = mpp[new_node->val];
        pair<TreeNode*,int> v1 = build(in,post,postind,mpp,ind+1,r);
        new_node->right = v1.first;
        pair<TreeNode*,int> v2 = build(in,post,v1.second,mpp,l,ind-1);
        new_node->left = v2.first;
        return {new_node,v2.second};
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++)
            mpp[inorder[i]] = i;
        return build(inorder,postorder,n-1,mpp,0,n-1).first;
    }
};