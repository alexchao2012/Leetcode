#include"head.h"

ListNode *partition(ListNode *head,ListNode *tail){
	int pivot=head->val;
	ListNode *slow=head,*fast=head->next;

	while(fast!=tail){
		if(fast->val<pivot){	//这里必须取小于，这样就可以保证pivot会被换到指定位置
			slow=slow->next;		//slow指的是当前的小于pivot的值，如果要交换先把slow后移
			swap(fast->val,slow->val);			
		}
		fast=fast->next;
	}
	
	swap(slow->val,head->val);

	return slow;
}
	
void _LQuickSort(ListNode *head,ListNode *tail){
	if(head->next!=tail){
		ListNode *p=partition(head,tail);
		_LQuickSort(head,p);
		_LQuickSort(p->next,tail);
	}
}

void LQuickSort(ListNode *head){
	if(!head || !head->next)return;

	_LQuickSort(head,NULL);//tail是要排序元素的下一位
}