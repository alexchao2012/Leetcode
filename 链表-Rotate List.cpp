#include"stage2.h"

ListNode *rotateRight1(ListNode *head, int k) {
	if(head==NULL || k<=0)return head;

	int length=1;
	ListNode *prob=head,*cur=head;
	while(prob->next){//ͳ������ĳ���
		++length;
		prob=prob->next;
	}
	prob->next=head;//���ӳɻ�

	int step=length-(k%length);//���㵹����k���ڵ��ǰһ��λ��
	while(--step)//�ҵ��ýڵ�
		cur=cur->next;
	head=cur->next;
	cur->next=NULL;
	return head;
}

ListNode *rotateRight(ListNode *head, int k) {
    if(k <= 0) return head;
    ListNode **prob = &head;
    int count = 0;
    while(*prob){
        prob = &((*prob)->next);
        ++count;
    }
    if(count <= 1) return head;
    k = k % count;
    *prob = head;//form a circle
        
    for(int i = 0 ; i < count - k; ++i) {
        prob = &((*prob)->next);
    }
    head = *prob;
    *prob = NULL;
        
    return head;
}