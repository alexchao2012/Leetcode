#include"head.h"

ListNode *partition(ListNode *head,ListNode *tail){
	int pivot=head->val;
	ListNode *slow=head,*fast=head->next;

	while(fast!=tail){
		if(fast->val<pivot){	//�������ȡС�ڣ������Ϳ��Ա�֤pivot�ᱻ����ָ��λ��
			slow=slow->next;		//slowָ���ǵ�ǰ��С��pivot��ֵ�����Ҫ�����Ȱ�slow����
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

	_LQuickSort(head,NULL);//tail��Ҫ����Ԫ�ص���һλ
}