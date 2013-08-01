#include"stage2.h"

ListNode *rotateRight1(ListNode *head, int k) {
	if(head==NULL || k<=0)return head;

	int length=1;
	ListNode *prob=head,*cur=head;
	while(prob->next){//统计链表的长度
		++length;
		prob=prob->next;
	}
	prob->next=head;//连接成环

	int step=length-(k%length);//计算倒数第k个节点的前一个位置
	while(--step)//找到该节点
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