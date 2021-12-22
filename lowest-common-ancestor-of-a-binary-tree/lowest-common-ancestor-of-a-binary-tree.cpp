/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    pair<vector<int>,TreeNode*> lca(TreeNode *node,int a,int b)
    {
        if(node == NULL)
            return {{0,0},NULL};
        pair<vector<int>,TreeNode*> left = lca(node->left,a,b);
        pair<vector<int>,TreeNode*> right = lca(node->right,a,b);
        if(left.second != NULL)
            return {{1,1},left.second};
        if(right.second != NULL)
            return {{1,1},right.second};
        if((left.first[0]&right.first[1]) == 1 || (left.first[1]&right.first[0]) == 1)
            return {{1,1},node};
        if(node->val == a && (left.first[1]==1 || right.first[1] == 1))
            return {{1,1},node};
        if(node->val == b && (left.first[0]==1 || right.first[0] == 1))
            return {{1,1},node};
        if(left.first[0] == 1 || right.first[0] == 1 || node->val == a)
            return {{1,0},NULL};
        if(left.first[1] == 1 || right.first[1] == 1 || node->val == b)
            return {{0,1},NULL};
        return {{0,0},NULL};
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pair<vector<int>,TreeNode*> ans = lca(root,p->val,q->val);
        return ans.second;
    }
};