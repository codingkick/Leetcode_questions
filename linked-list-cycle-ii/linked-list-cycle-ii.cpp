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
    ListNode *detectCycle(ListNode *head) {
        ListNode *t = head,*h = head;
        int count = 0;
        ListNode *ans = NULL;
        while(h!=NULL && h->next != NULL && count<2)
        {
            if(t == h)
            {
                count++;
                ans = t;
            }
            t = t->next;
            h = h->next->next;
        }
        if(count<2)
            return NULL;
        else
        {
            ListNode *p1 = head,*p2 = ans;
            while(p1 != p2)
            {
                p1 = p1->next;
                p2 = p2->next;
            }
            return p1;
        }
    }
};