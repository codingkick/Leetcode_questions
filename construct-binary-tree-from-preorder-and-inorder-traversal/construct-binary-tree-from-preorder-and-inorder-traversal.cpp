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
    int preind;
    TreeNode* tree(vector<int> &pre,vector<int> &in,int l,int r,unordered_map<int,int> &mpp)
    {
        if(l>r)
            return NULL;
        TreeNode *node = new TreeNode();
        node->val = pre[preind];
        preind++;
        node->left = tree(pre,in,l,mpp[node->val]-1,mpp);
        node->right = tree(pre,in,mpp[node->val]+1,r,mpp);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mpp;
        int n = inorder.size();
        for(int i=0;i<n;i++)
            mpp[inorder[i]] = i;
        preind = 0;
        return tree(preorder,inorder,0,n-1,mpp);
    }
};