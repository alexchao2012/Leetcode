#include"head.h"

ListNode *removeNthFromEnd3(ListNode *head, int n) {  
    if(head == NULL) return NULL;  

    ListNode dummy(-1);  
    dummy.next = head;  

    ListNode* p = dummy.next;  
    ListNode* prevP = &dummy;  
    ListNode* q = dummy.next;  

    for(int i = 0; i < n; ++i)  
        q = q->next;  

    while(q != NULL)  
    {  
        q = q->next;  
        prevP = p;  
        p = p->next;  
    }  

    prevP->next = p->next;  

    return dummy.next;  
}

ListNode *removeNthFromEnd(ListNode *head,int n){
	if (!head) return NULL;            
	if (n <= 0) return NULL;   

	ListNode* fast = head;  
	ListNode** slow = &head;  

	int k = 0;  
	while (k < n){  
		if (!fast) return NULL;  
			fast = fast->next;  
		++k;  
	}  

	while (fast){  
		fast = fast->next;  
		slow = &(*slow)->next;  
		//slow=&((*(*slow)).next);
	}    
	*slow = (*slow)->next;  
	return head;  	
}

ListNode *removeNthFromEnd1(ListNode *head,int n){
	if(NULL==head->next || n<=0)
		return NULL;
	ListNode *prob,*cur,*pre;
	pre=NULL;
	cur=prob=head;

	int i=0;
	while(i<n){
		if(NULL==prob)
			return head;
		prob=prob->next;
		++i;
	}

	while(prob){
		pre=cur;
		cur=cur->next;
		prob=prob->next;
	}
	if(!pre)
		return cur->next;
	else{
		pre->next=cur->next;
		return head;
	}
}
