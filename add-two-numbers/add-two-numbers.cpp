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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1=0,n2=0;
        ListNode* ptr = l1;
        while(ptr!=NULL)
        {
            n1++;
            ptr = ptr->next;
        }
        ptr = l2;
        while(ptr!=NULL)
        {
            n2++;
            ptr = ptr->next;
        }
        if(n2>n1)
            return addTwoNumbers(l2,l1);
        ptr = l1;
        int carry = 0,temp = 0;
        ListNode *last = NULL,*ptr2 = l2;
        while(ptr!=NULL)
        {
            if(ptr2 != NULL)
                temp = ptr->val + ptr2->val + carry;
            else
                temp = ptr->val + carry;
            ptr->val = temp%10;
            carry = (int)temp/10;
            last = ptr;
            ptr = ptr->next;
            if(ptr2!=NULL)
            ptr2 = ptr2->next;
        }
        if(carry > 0)
        {
            ListNode *new_node = new ListNode();
            new_node->val = carry;
            last->next = new_node;
        }
        return l1;
    }
};