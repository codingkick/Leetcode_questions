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
    ListNode* func(ListNode *head,int left,int right,int curr)
    {
        if(curr<left)
        {
            head->next = func(head->next,left,right,curr+1);
            return head;
        }
        else if(curr>right)
            return head;
        else
        {
            ListNode *ptr = head->next;
            ListNode *pre = head;
            curr++;
            while(curr<=right)
            {
                ListNode *next_node = ptr->next;
                ptr->next = pre;
                pre = ptr;
                ptr = next_node;
                curr++;
            }
            head->next = ptr;
            return pre;
        } 
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        return func(head,left,right,1);
    }
};