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
    bool samepar(TreeNode *node,int x,int y)
    {
        if(node == NULL)
            return false;
        int v1 = 0,v2 = 0;
        if(node->left!=NULL)
            v1 = node->left->val;
        if(node->right!=NULL)
            v2 = node->right->val;
        if((v1 == x || v1 == y) && (v2 == x || v2 == y))
            return true;
        bool a1 = samepar(node->left,x,y);
        bool a2 = samepar(node->right,x,y);
        if(a1 == true || a2 == true)
            return true;
        else
            return false;
    }
    bool bfs(TreeNode *node,int x,int y)
    {
        queue<TreeNode*> q1;
        q1.push(node);
        while(!q1.empty())
        {
            int s = q1.size();
            bool one = false, two = false;
            while(s--)
            {
                TreeNode *temp = q1.front();
                if(temp->val == x)
                    one = true;
                if(temp->val == y)
                    two = true;
                q1.pop();
                if(temp->left != NULL)
                    q1.push(temp->left);
                if(temp->right != NULL)
                    q1.push(temp->right);
            }
            if(one == true && two == true)
                return true;
        }
        return false;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        bool temp = samepar(root,x,y);
        if(temp == true)
            return false;
        return bfs(root,x,y);
    }
};