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
    TreeNode* gen(vector<int> &pre,vector<int> &post,unordered_map<int,int> &mpp,int a,int b,int c,int d)
    {
        if(a>b || c>d)
            return NULL;
        // int n = pre.size();
        TreeNode* new_node = new TreeNode(pre[a]);
        if(a+1>b)
            return new_node;
        int ind = mpp[pre[a+1]];
        int len = ind-c+1;
        new_node->left = gen(pre,post,mpp,a+1,a+len,c,c+len-1);
        new_node->right = gen(pre,post,mpp,a+len+1,b,c+len,d-1);
        return new_node;
        
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++)
            mpp[postorder[i]] = i;
        return gen(preorder,postorder,mpp,0,n-1,0,n-1);
    }
};