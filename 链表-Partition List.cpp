#include"stage2.h"
/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,//要求是稳定的partition
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

ListNode *partition(ListNode *head, int x) {
	if(!head || !head->next)return head;

	ListNode *smaller=NULL,*bigger=NULL,*cur=head;
	ListNode **s=&smaller,**b=&bigger;

	while(cur){
		if(cur->val<x){
			*s=cur;
			s=&(*s)->next;
		}
		else{
			*b=cur;
			b=&(*b)->next;
		}
		cur=cur->next;
	}
	*b=NULL;
	if(!smaller)
		return bigger;
	*s=bigger;

	return smaller;
}

ListNode *partition2(ListNode *head,int x){//使用dummy指针避免了很多边界问题
	if(!head)return NULL;

	ListNode dumLeft(0);
	ListNode dumRight(0);

	ListNode *preLeft=&dumLeft;
	ListNode *preRight=&dumRight;

	ListNode *cur=head;

	while(cur != NULL){
		if(cur->val >= x){
			preRight->next=cur;
			preRight=preRight->next;
		}
		else{
			preLeft->next=cur;
			preLeft=preLeft->next;
		}

		cur=cur->next;
	}

	preLeft->next=dumRight.next;
	preRight->next=NULL;

	return dumLeft.next;
}