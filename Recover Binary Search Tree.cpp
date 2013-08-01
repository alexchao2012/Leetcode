#include"stage3.h"
/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/

void treeWalk(TreeNode* root, TreeNode*& prv, TreeNode*& first, TreeNode*& second) {
	//geeksforgeeks上面有相同的一个题目，可以参考，思路一样！,D盘:Tree 中有
	//注意参数传递的是指针的引用，如果要改变指针内容，那么需要传入一个二级指针，或一个引用
	if(root==NULL) return; 
	treeWalk(root->left,prv,first,second); 
	if((prv!=NULL)&&(prv->val>root->val)){ 
		if(first==NULL) 
			first=prv; 
		second=root; 
	}
	prv=root; 
	treeWalk(root->right,prv,first,second); 
}
void recoverTree(TreeNode *root) {
	TreeNode* first=NULL;
	TreeNode* second=NULL; 
	TreeNode* prv=NULL;
	treeWalk(root,prv,first,second);
	swap(first->val,second->val); 
}
