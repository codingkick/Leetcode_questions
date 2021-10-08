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
    int ans;
    vector<int>dfs(TreeNode *node)
    {
        
        if(node->left == NULL && node->right == NULL)
        {
            // cout<<"bst at : "<<node->val<<"\n";
            ans = max(ans,node->val);
            return {node->val,node->val,node->val};
        }
        else if(node->left == NULL && node->right != NULL)
        {
            vector<int> v2 = dfs(node->right);
            if(v2[0] == 50000 && v2[1] == 50000)
                return {50000,50000,0};
            if(node->val < v2[0])
            {
                // cout<<"bst at : "<<node->val<<"\n";
                int s = node->val + v2[2];
                ans = max(ans,s);
                return {node->val,v2[1],s};
            }
            else
            {
                return {50000,50000,0};
            }
        }
        else if(node->left != NULL && node->right == NULL)
        {
            vector<int> v1 = dfs(node->left);
            if(v1[0] == 50000 && v1[1] == 50000)
                return {50000,50000,0};
            if(node->val > v1[1])
            {
                // cout<<"bst at : "<<node->val<<"\n";
                int s = node->val + v1[2];
                ans = max(ans,s);
                return {v1[0],node->val,s};
            }
            else
            {
                return {50000,50000,0};
            }
        }
        else
        {
            vector<int> v1 = dfs(node->left);
            vector<int> v2 = dfs(node->right);
            if(v1[0] == 50000 && v1[1] == 50000 || (v2[0] == 50000 && v2[1] == 50000))
                return {50000,50000};
            if(node->val > v1[1] && node->val < v2[0])
            {
                // cout<<"bst at : "<<node->val<<"\n";
                int s = node->val + v1[2] + v2[2];
                ans = max(ans,s);
                return {v1[0],v2[1],s};
            }
            else
            {
                return {50000,50000,0};
            }
        }
        
    }
    int maxSumBST(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};