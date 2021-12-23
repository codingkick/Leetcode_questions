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
    bool is_bst(TreeNode *node,int mini,int maxi)
    {
        if(node == NULL)
            return true;
        if(node->val>mini && node->val<maxi)
        {
            bool v1 = is_bst(node->left,mini,node->val);
            bool v2 = is_bst(node->right,node->val,maxi);
            if(v1 == true && v2 == true)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int,TreeNode*> mpp;
        int n = trees.size();
        if(n == 1)
        {
            bool v1 = is_bst(trees[0],INT_MIN,INT_MAX);
            if(v1 == true)
                return trees[0];
            else
                return NULL;
        }
        unordered_map<TreeNode*,int> mpp2;
        for(int i=0;i<n;i++)
        {
            TreeNode *temp = trees[i];
            mpp2[temp] = 0;
            if(temp->left!=NULL)
            {
                if(mpp.find(temp->left->val) != mpp.end())
                    return NULL;
                mpp[temp->left->val] = temp;
            }
            if(temp->right!=NULL)
            {
                if(mpp.find(temp->right->val) != mpp.end())
                    return NULL;
                mpp[temp->right->val] = temp;
            }
        }
        TreeNode *ans = trees[0],*root = NULL;
        int count = 0;
        for(int i=0;i<n;i++)
        {
            TreeNode *temp = trees[i];
            int l = 0,r = 0;
            if(temp->left!=NULL)
                l = temp->left->val;
            if(temp->right!=NULL)
                r = temp->right->val;
            if(mpp.find(temp->val) != mpp.end())
            {
                TreeNode *node = mpp[temp->val];
                if(node->left!=NULL && node->left->val == temp->val)
                {
                    if(node->val == l || node->val == r)
                        return NULL;
                    node->left->left = temp->left;
                    node->left->right = temp->right;
                    if(temp->left!=NULL)
                        mpp[temp->left->val] = node->left;
                    if(temp->right!=NULL)
                        mpp[temp->right->val] = node->left;
                    ans = node->left;
                    mpp2[node] += 1;
                }
                else if(node->right!=NULL && node->right->val == temp->val)
                {
                    if(node->val == l || node->val == r)
                        return NULL;
                    node->right->left = temp->left;
                    node->right->right = temp->right;
                    if(temp->left!=NULL)
                        mpp[temp->left->val] = node->right;
                    if(temp->right!=NULL)
                        mpp[temp->right->val] = node->right;
                    ans = node->right;
                    mpp2[node] += 1;
                }   
            }
            else
            {
                count++;
                root = trees[i];
            }
        }
        // cout<<count<<"\n";
        if(count>1 || count == 0)
            return NULL;
        else if(count == 1)
        {
            // cout<<root->val<<"\n";
            if(mpp2[root] == 0)
                return NULL;
        }
        while(mpp.find(ans->val)!=mpp.end())
        {
            ans = mpp[ans->val];
        }
        // cout<<ans->val<<"\n";
        bool v = is_bst(ans,INT_MIN,INT_MAX);
        if(v == true)
            return ans;
        else
            return NULL;
    }
};