#include<iostream>
using namespace std;

void swap(int &x,int &y){
	int tmp = x;
	x = y;
	y = tmp;
}

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int _x):val(_x),next(NULL){}
};

ListNode *partition(ListNode *head,ListNode *tail){
	if(head != tail){
		int pivot = head->val;
		ListNode *slow = head;
		ListNode *fast = head->next;

		while(fast != tail){
			if(fast->val < pivot){
				slow = slow->next;
				swap(slow->val,fast->val);
			}
			fast = fast->next;
		}
		swap(head->val,slow->val);

		return slow;
	}
}

void _listQuickSort(ListNode *head,ListNode *tail){
	if(head != tail && head->next != tail){
		ListNode *pivot = partition(head,tail);
		_listQuickSort(head,pivot);
		_listQuickSort(pivot->next,tail);
	}
}

void listQuickSort(ListNode *head){
	_listQuickSort(head,NULL);
}

int main(){
	ListNode l1(5),l2(4),l3(3),l4(2),l5(1);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next =&l5;

	listQuickSort(&l1);

	ListNode *head = &l1;
	while(head != NULL){
		cout << head->val << '\t';
		head = head->next;
	}
	cout<<endl;

	return 0;
}
		
