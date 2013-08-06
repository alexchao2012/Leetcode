#include"stage2.h"
/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/
ListNode *deleteDuplicates2(ListNode *head) {//没有释放内存，不好
	if(!head || !head->next)return head;

	ListNode *cur=head->next,**link=&head->next;
	int v=head->val;
	while(cur){
		if(v!=cur->val){
			v=cur->val;
			*link=cur;
			link=&(*link)->next;
		}
		cur=cur->next;
        *link=NULL;//如果有重复元素，就把这个域的next值先设置成NULL，这样来了新的值自然会连接上去
	}

	return head;
}

ListNode *deleteDuplicates3(ListNode *head){//使用覆盖，有效防止内存泄露
	if(!head || !head->next)return head;

	ListNode *p1=head->next,*p0=head;
	while(p1){
		if(p1->val!=p0->val){
			p0=p0->next;
			p0->val=p1->val;
		}
		p1=p1->next;
	}
	ListNode *removed=p0->next;
	p0->next=NULL;
	while(removed){
		ListNode *temp=removed;
		removed=removed->next;
		delete temp;
	}
	return head;
}