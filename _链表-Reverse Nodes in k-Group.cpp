#include"head.h"
/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

ListNode *reverse(ListNode *pre, ListNode *next) {
    ListNode *last = pre->next;
    ListNode *cur = last->next;
    while (cur != next) {
        last->next = cur->next;
        cur->next = pre->next;
        pre->next = cur;

        cur = last->next;
    }
    return last;
}

ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head || k <= 1) return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode *pre = &dummy;

    int i = 0;
    while (head) {
        i++;
        if (i % k == 0) {
            pre = reverse(pre, head->next);                
            head = pre->next;
        } else {
            head = head->next;   
        }
    }

    return dummy.next;
}

//int main(){
//	ListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6),l7(7),l8(8);
//	l1.next=&l2;l2.next=&l3;l3.next=&l4;l4.next=&l5;
//	l5.next=&l6;l6.next=&l7;l7.next=&l8;
//
//	ListNode *head=reverseKGroup(&l1,3);
//
//	while(head!=NULL){
//		cout<<head->val<<endl;
//		head=head->next;
//	}
//
//	return 0;
//}