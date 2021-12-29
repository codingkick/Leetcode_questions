/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void bfs(Node *node)
    {
        queue<Node*> q1;
        q1.push(node);
        while(!q1.empty())
        {
            int s = q1.size();
            Node *last = NULL;
            while(s--)
            {
                Node *temp = q1.front();
                q1.pop();
                if(temp->left!=NULL)
                {
                    q1.push(temp->left);
                    if(last != NULL)
                    {
                        last->next = temp->left;
                        last = temp->left;
                    }
                    else
                        last = temp->left;
                }
                if(temp->right!=NULL)
                {
                    q1.push(temp->right);
                    last->next = temp->right;
                    last = temp->right;
                }
            }
        }
    }
    Node* connect(Node* root) {
        if(root == NULL)
            return NULL;
        bfs(root);
        return root;
    }
};