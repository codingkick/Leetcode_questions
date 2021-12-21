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
    int length(ListNode* head)
    {
        ListNode* ptr = head;
        int l = 0;
        while(ptr!=NULL)
        {
            l++;
            ptr = ptr->next;
        }
        return l;
    }
    ListNode* func(ListNode *head,int k,int revc)
    {
        if(revc == 0)
            return head;
        ListNode* ptr = head->next;
        int count = 1;
        ListNode* pre = head;
        while(count<k && ptr!=NULL)
        {
            ListNode* next = ptr->next;
            ptr->next = pre;
            pre = ptr;
            ptr = next;
            count++;
        }
        if(ptr!=NULL)
        {
            head->next = func(ptr,k,revc-1);
        }
        else
            head->next = NULL;
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int l = length(head);
        int revc = l/k;
        return func(head,k,revc);
    }
};