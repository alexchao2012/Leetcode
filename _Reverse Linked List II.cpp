#include"stage2.h"
/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ? m ? n ? length of list.
*/
ListNode *reverseBetween(ListNode *head, int m, int n) {
    if(!head || !head->next || m>=n)return head;
    ListNode *pre=NULL,*cur=head,*post;
	ListNode **ppre1,**ppre2;

	int cnt=1;

	while(cur && cnt<m){
		pre=cur;
		cur=cur->next;		
		++cnt;
	}
	if(!pre)
		ppre1=&head;
	else
		ppre1=&pre->next;

	ppre2=&cur->next;
	while(cnt<=n){//做逆转的时候，要这样写
		post=cur->next;
		cur->next=pre;
		pre=cur;
		cur=post;
		++cnt;
	}
	*ppre2=cur;
	*ppre1=pre;	

	return head;
}