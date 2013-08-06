#include"head.h"
/*
Given a linked list, swap every two adjacent nodes and return its head.
For example,
	Given 1->2->3->4, you should return the list as 2->1->4->3.
Your algorithm should use only constant space. 
You may not modify the values in the list, only nodes itself can be changed.
*/
ListNode *swapPairs(ListNode *head){
    ListNode **ppre = &head;
        
    while(true) {
        ListNode *n0 = *ppre;
        if(NULL == n0) return head;
        ListNode *n1 = n0->next;
        if(NULL == n1) return head;
            
        //swap n0 and n1
        *ppre = n1;
        n0->next = n1->next;
        n1->next = n0;
        //ListNode *next = n1->next;
        ppre = &(n0->next);
    }        
    return head;
}
ListNode *swapPairs2(ListNode *head) {  
    ListNode** curNext = &head;  
    while(NULL != *curNext && NULL != (*curNext)->next)  
    {  
        ListNode* temp = (*curNext)->next;  
        (*curNext)->next = (*curNext)->next->next;  
        temp->next = *curNext;  
        *curNext = temp;  
        curNext = &(*curNext)->next->next;  
    }  
    return head;  
}