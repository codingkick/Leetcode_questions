/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> pos(ListNode* ptr,ListNode* pre_node,ListNode* head)
    {
        ListNode *h = head;
        ListNode* p = head;
        ListNode* pre = NULL;
        ListNode *n = ptr->next;
        // cout<<"for "<<ptr->val<<" the pre is : "<<pre_node->val<<"\n";
        ListNode *pv = ptr;
        while(p!=ptr)
        {
            if(p->val > ptr->val)
            {
                if(pre == NULL)
                {
                    h = ptr;
                }
                else
                {
                    // cout<<"for "<<ptr->val<<" the prev is "<<pre->val<<"\n";
                    pre->next = ptr;
                }
                ptr->next = p;
                pre_node->next = n;
                pv = pre_node;
                // cout<<"next to "<<ptr->val<<" is : "<<p->val<<"\n";
                break;
            }
            else
            {
                // cout<<"for "<<ptr->val<<" "<<p->val<<" is smaller\n";
                pre = p;
                p = p->next;
            }
        }
        ListNode *tmp = h;
        return {h,n,pv};
    }
    ListNode* func(ListNode *node)
    {
        ListNode *head = node;
        ListNode *ptr = head->next;
        ListNode *pre_node = head;
        while(ptr!=NULL)
        {
            vector<ListNode*> temp = pos(ptr,pre_node,head);
            head = temp[0];
            // cout<<"for "<<ptr->val<<"the head is : "<<head->val<<"\n";
            ptr = temp[1];
            pre_node = temp[2];
        }
        return head;
    }
    ListNode* insertionSortList(ListNode* head) {
        return func(head);
    }
};