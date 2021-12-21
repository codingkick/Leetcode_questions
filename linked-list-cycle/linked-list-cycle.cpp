/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode *t = head,*h = head;
        int count = 0;
        while(h!=NULL && h->next!=NULL && count<2)
        {
            if(t == h)
                count++;
            t = t->next;
            h = h->next->next;
        }
        if(count==2)
            return true;
        else
            return false;
    }
};