#include"stage3.h"
/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/
bool isSameTree(TreeNode *p, TreeNode *q) {//Ҫע�� ����������˼ά��ʽ�ģ�
	if(!p && !q)return true;
	if(!p || !q)return false;

	return p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}
