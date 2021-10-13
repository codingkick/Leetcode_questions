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
    pair<TreeNode*,int> build(vector<int> &preorder,int preind,int mini,int maxi)
    {
        if(preind>=preorder.size())
            return {NULL,preind};
        // cout<<preind<<" "<<mini<<" "<<maxi<<"\n";
        if(preorder[preind] > mini && preorder[preind] < maxi)
        {
            // cout<<"a:\n";
            TreeNode *new_node = new TreeNode();
            new_node->val = preorder[preind];
            preind++;
            pair<TreeNode*,int> v1 = build(preorder,preind,mini,new_node->val);
            new_node->left = v1.first;
            pair<TreeNode*,int> v2 = build(preorder,v1.second,new_node->val,maxi);
            new_node->right = v2.first;
            return {new_node,v2.second};
        }
        else
        {
            // cout<<"b\n";
            return {NULL,preind};
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preind = 0;
        return build(preorder,preind,INT_MIN,INT_MAX).first;
    }
};