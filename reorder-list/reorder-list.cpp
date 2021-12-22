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
    ListNode* func(ListNode* head,ListNode* last)
    {
        if(head == NULL)
            return NULL;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        ptr1->next = last;
        if(last != NULL)
        last->next = func(ptr2,last->next);
        return ptr1;
    }
    int length(ListNode* head)
    {
        int l = 0;
        while(head!=NULL)
        {
            l++;
            head = head->next;
        }
        return l;
    }
    ListNode* reverse(ListNode *p)
    {
        if(p == NULL)
            return NULL;
        ListNode *pre = p;
        ListNode *p2 = p->next;
        p->next = NULL;
        p = p2;
        while(p!=NULL)
        {
            ListNode *next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        return pre;
    }
    void reorderList(ListNode* head) {
        int l = length(head);
        int val = (l+1)/2;
        ListNode *ptr = head;
        ListNode *lst = head;
        while(val--)
        {
            lst = ptr;
            ptr = ptr->next;
        }
        lst->next = NULL;
        // cout<<ptr->val<<" ";
        ListNode *p = reverse(ptr);
        // while(p!=NULL)
        // {
        //     cout<<p->val<<" ";
        //     p = p->next;
        // }
        func(head,p);
    }
};