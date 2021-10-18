/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string intostr(int n)
    {
        string ret = "";
        if(n == 0)
        {
            ret += '0';
            return ret;
        }
        while(n>0)
        {
            char temp = (n%10) + '0';
            ret = temp + ret;
            n = n/10;
        }
        return ret;
    }
    string pre(TreeNode *node)
    {
        if(node == NULL)
        {
            string ret = "";
            ret += '#';
            return ret;
        }
        string ins = intostr(node->val) +','+pre(node->left)+','+pre(node->right);
        return ins;
    }
    string serialize(TreeNode* root) {
        string ans = pre(root);
        // cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    vector<int> strtoint(string data,int ind)
    {
        int i = ind;
        int n = data.length();
        int ret = 0;
        if(data[ind] == '#')
        {
            ind+=2;
            return {-1,ind};
        }
        while(i<n && data[i] != ',')
        {
            ret = ret*10 + (data[i]-'0');
            i++;
        }
        i++;
        return {ret,i};
    }
    pair<TreeNode*,int> build(string data,int ind)
    {
        int n = data.length();
        if(ind>=n)
            return {NULL,ind};
        TreeNode *new_node = new TreeNode();
        vector<int> value = strtoint(data,ind);
        if(value[0] == -1)
        {
            return {NULL,value[1]};
        }
        else
        {
            new_node->val = value[0];
            pair<TreeNode*,int> v1 = build(data,value[1]);
            pair<TreeNode*,int> v2 = build(data,v1.second);
            new_node->left = v1.first;
            new_node->right = v2.first;
            return {new_node,v2.second};
        }
    }
    TreeNode* deserialize(string data) {
        pair<TreeNode*,int> ans = build(data,0);
        return ans.first;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;