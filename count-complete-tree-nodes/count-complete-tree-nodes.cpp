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
    int height(TreeNode *node)
    {
        if(node == NULL)
            return 0;
        return 1 + height(node->left);
    }
    bool pos(TreeNode *node,int num,int maxnode)
    {
        if(maxnode == 1)
            return true;
        if(num > maxnode/2)
        {
            // right
                if(node->right == NULL)
                    return false;
            return pos(node->right,num-(maxnode)/2,maxnode/2);
        }
        else
        {
            // left
                if(node->left == NULL)
                    return false;
            return pos(node->left,num,maxnode/2);
        }
    }
    int countNodes(TreeNode* root) {
        // int l = 0,r = 50000;
        if(root == NULL)
            return 0;
        int h = height(root)-1;
        int maxnode = pow(2,h);
        // cout<<pos(root,1,maxnode);
        // cout<<pos(root,2,maxnode);
        // cout<<pos(root,3,maxnode);
        // cout<<pos(root,4,maxnode);
        // return 1;
        int ans = 0;
        int l = 1,r = maxnode;
        while(l<=r)
        {
            int mid = (l+r)/2;
            bool temp = pos(root,mid,maxnode);
            if(temp == true)
            {
                ans = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        return maxnode-1 + ans;
    }
};