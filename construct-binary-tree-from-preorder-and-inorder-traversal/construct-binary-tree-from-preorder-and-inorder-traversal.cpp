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
    pair<TreeNode*,int> build(vector<int>& pre, vector<int>& in,int preind,unordered_map<int,int> &mpp,int l,int r)
    {
        if(l>r)
            return {NULL,preind};
        TreeNode *new_node = new TreeNode();
        new_node->val = pre[preind];
        preind++;
        int ind = mpp[new_node->val];
        pair<TreeNode*,int> v1 = build(pre,in,preind,mpp,l,ind-1);
        new_node->left = v1.first;
        pair<TreeNode*,int> v2 = build(pre,in,v1.second,mpp,ind+1,r);
        new_node->right = v2.first;
        return {new_node,v2.second};
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mpp;
        int n = inorder.size();
        for(int i=0;i<n;i++)
            mpp[inorder[i]] = i;
        return build(preorder,inorder,0,mpp,0,n-1).first;
    }
};