#include"stage3.h"
/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/
/*trick�����Ľ���
The method 1 constructs the tree from root to leaves. 
In this method, we construct from leaves to root. ����Ҷ�ڵ㿪ʼ������
The idea is to insert nodes in BST in the same order
as the appear in Linked List, so that the tree can be
constructed in O(n) time complexity. We first count 
the number of nodes in the given Linked List. Let the
count be n. After counting nodes, we take left n/2 nodes
and recursively construct the left subtree. After left
subtree is constructed, we allocate memory for root and
link the left subtree with root. Finally, we recursively
construct the right subtree and link it with root.

While constructing the BST, we also keep moving the 
list head pointer to next so that we have the appropriate 
pointer in each recursive call.

*/
TreeNode* sortedListToBST(ListNode *& list,int start,int end) {//O(n)�ķ�������Ҫ����
	if (start > end) return NULL;
	int mid = start + (end - start) / 2; 
	TreeNode *leftChild = sortedListToBST(list, start, mid-1); 
	TreeNode *parent = new TreeNode(list->val); 
	parent->left = leftChild; 
	list = list->next; 
	parent->right = sortedListToBST(list, mid+1, end); 
	return parent; 
}
TreeNode *sortedListToBST(ListNode *head) { 
	int n = 0; 
	ListNode* x = head;
	while(x){
		n++;
		x=x->next;
	} 
	return sortedListToBST(head, 0, n-1);
} 


ListNode *findMidien(ListNode *head,ListNode *rear){//����һ��ע����Ʊ߽磬���ܶ༸�д��룬ҲӦ���ȱ�֤bug-free
	//���Ӷ�̫�ߣ����ã���֮���ã�
    if(head==rear || head->next==rear)return head;
	ListNode *slow=head,*fast=head->next;
	while(fast!=rear && fast->next!=rear){
		slow=slow->next;
		fast=fast->next->next;
	}

	return slow;
}

TreeNode *build(ListNode *head,ListNode *rear){
	if(head==rear)return NULL;

	ListNode *mid=findMidien(head,rear);

	TreeNode *root=new TreeNode(mid->val);

	root->left=build(head,mid);//��һ�仰��������ģ��м�ֵ�Ѿ��������ˣ���Ӧ���ٿ������ֵ��!
	root->right=build(mid->next,rear);

	return root;
}

TreeNode *sortedListToBST2(ListNode *head) {
	return build(head,NULL);
}

