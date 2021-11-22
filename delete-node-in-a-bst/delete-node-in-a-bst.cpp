class Solution {
public:
    vector<int> storage;
    TreeNode* deleteNode(TreeNode* root, int key) {
        preOrderDFS(root,key);
        sort(storage.begin(),storage.end());
        int start = 0;
        int end = storage.size()-1;
        TreeNode* newroot = NULL;
        newroot = convert(storage,start,end,newroot);
        return newroot;
    }
    
    //getNewNode
    TreeNode* getNewNode(int data){
        TreeNode* newNode = new TreeNode;
        newNode->val = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    
    //preOrder function
    void preOrderDFS(TreeNode* root,int key){
        if(root==NULL) return;
        if(root->val!=key){
           storage.push_back(root->val); 
        } 
        preOrderDFS(root->left,key);
        preOrderDFS(root->right,key);
    }
    
    //convert function
    TreeNode* convert(vector<int> &a , int start , int end , TreeNode* root){
        if(start > end)
        {
            root = NULL;
        }
        else
        {
            int mid = (start+end)/2;
            root = getNewNode(a[mid]);
            root->left = convert(a,start,mid-1,root->left);
            root->right = convert(a,mid+1,end,root->right);
        }
        return root;
       }
};