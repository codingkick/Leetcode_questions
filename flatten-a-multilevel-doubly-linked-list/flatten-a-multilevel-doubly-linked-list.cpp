/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flat(Node *head,Node *last)
    {
        if(head==NULL)
        return last;
        
        last->next = head;
        head->prev = last;
            
        Node *ptr = head;
        while(ptr!=NULL)
        {
            last = ptr;
            Node *tmp = ptr->next;
            if(ptr->child!=NULL)
            {
                last = flat(ptr->child,last);
            }
            ptr->child = NULL;
            last->next = tmp;
            if(tmp!=NULL)
            tmp->prev = last;
            ptr = tmp;
        }
        return last;
    }
    Node* flatten(Node* head) {
        if(head == NULL)
            return NULL;
        Node *t = new Node();
        flat(head,t);
        head->prev = NULL;
        return head;
    }
};