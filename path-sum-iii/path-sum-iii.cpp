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
    int dfs(TreeNode *node,int t,unordered_map<int,int> &mpp,int curr)
    {
        if(node == NULL)
            return 0;
        int count = 0;
        int sum = curr + node->val;
        if(mpp.find(sum - t) != mpp.end())
        {
            count += mpp[sum - t];
        }
        if(mpp.find(sum) == mpp.end())
            mpp[sum] = 1;
        else
            mpp[sum] += 1;
        count += dfs(node->left,t,mpp,sum);
        count += dfs(node->right,t,mpp,sum);
        mpp[sum] -= 1;
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        return dfs(root,targetSum,mpp,0);
    }
};