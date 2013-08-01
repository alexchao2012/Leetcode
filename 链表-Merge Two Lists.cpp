#include"head.h"

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
	ListNode *head=NULL,**cur=&head;//使用**p，非常重要，通过每次修改next中的值实现整条链的重建

	while(l1 && l2){
		if(l1->val<=l2->val){
			*cur=l1;
			l1=l1->next;
		}
		else{
			*cur=l2;
			l2=l2->next;
		}
		cur=&(*cur)->next;
	}
	
	l1==NULL?(*cur=l2):(*cur=l1);

	return head;
}

ListNode *mergeTwoLists9(ListNode *l1,ListNode *l2){
	if(l1==NULL)return l2;
	if(l2==NULL)return l1;

	ListNode *head=NULL,*cur=NULL;
	ListNode *p=l1,*q=l2;

	while(p && q){
		ListNode *temp;

		if(p->val < q->val){
			temp=p;
			p=p->next;
		}
		else{
			temp=q;
			q=q->next;
		}

		if(head==NULL)	
			head=cur=temp;
		else{
			cur->next=temp;
			temp->next=NULL;
			cur=temp;
		}
	}

	if(p)
		cur->next=p;
	else if(q)
		cur->next=q;

	return head;
}





/*对使用指针的指针的单步解释程序
	ListNode l1(1),l2(2),l3(3),l4(4),l5(5);
	l1.next=&l2;
	l2.next=&l3;
	l3.next=&l4;
	l4.next=&l5;

	ListNode *res=NULL,*head=&l1;
	ListNode **cur=&res;

	cout<<"head  "<<head<<endl;

	*cur=head;
	cout<<"res  "<<res<<endl;
	cout<<"cur  "<<cur<<endl;

	cur=&head->next;
	head=head->next;

	cout<<"res->next  "<<res->next<<endl;
	cout<<"head  "<<head<<endl;
	cout<<"cur  "<<cur<<endl;

	*cur=head;
	cout<<"cur  "<<cur<<endl;
*/