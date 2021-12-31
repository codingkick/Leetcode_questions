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
    int dfs(TreeNode *node,map<int,int> &curr)
    {
        if(node == NULL)
            return INT_MIN;
        int val = node->val;
        int ans = INT_MIN;
        if(curr.size()!=0)
        {
            int mini = curr.begin()->first;
            int maxi = (prev(curr.end()))->first;
            // cout<<"for "<<val<<" maxi: "<<maxi<<" mini : "<<mini<<"\n";
            ans = max(abs(mini-val),abs(maxi-val));
        }
        if(curr.find(val) == curr.end())
        curr[val] = 1;
        else
        curr[val] += 1;
        ans = max(ans,dfs(node->left,curr));
        ans = max(ans,dfs(node->right,curr));
        curr[val] -= 1;
        if(curr[val] == 0)
            curr.erase(val);
        return ans;
    }
    int maxAncestorDiff(TreeNode* root) {
        map<int,int> curr;
        return dfs(root,curr);
    }
};