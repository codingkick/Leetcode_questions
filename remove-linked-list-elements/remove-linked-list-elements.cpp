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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return NULL;
        ListNode *ptr = head->next,*last = head;
        while(ptr!=NULL)
        {
            if(ptr->val == val)
            {
                last->next = ptr->next;
            }
            else
            {
                last = ptr;
            }
            ptr = ptr->next;
        }
        if(head->val == val)
            return head->next;
        return head;
    }
};