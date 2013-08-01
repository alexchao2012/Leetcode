#include"stage2.h"
/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/


ListNode *deleteDuplicates4(ListNode *head) {  
    ListNode** curNext = &head;  
    ListNode* cur = head;  
    while(NULL != cur)  
    {  
        ListNode* temp = cur;  
        while(NULL != cur->next && cur->next->val == cur->val)  
            cur = cur->next;  
        if(cur == temp)  
        {  
            *curNext = temp;  
            curNext = &(*curNext)->next;  
        }  
        cur = cur->next;  
    }  
    *curNext = NULL;  
    return head;  
}

ListNode *deleteDuplicates(ListNode *head) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode *pre = &dummy, *cur = head;
    while (cur) {
        int i = cur->val;
        if (cur->next && cur->next->val == i) {
            while (cur && cur->val == i) {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            }
            cur = pre;
        }
        pre = cur;
        cur = cur->next;
    }

    return dummy.next;
}