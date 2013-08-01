#include"stage3.h"
/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

bool _isBalanced(TreeNode *root,int *height){//树形DP方法
	if(!root){
		*height=0;
		return true;
	}

	int left,right;

	if(_isBalanced(root->left,&left) && _isBalanced(root->right,&right)){
		if(abs(left-right) <= 1){
			*height=max(left,right)+1;
			return true;
		}
	}

	return false;
}

bool isBalanced(TreeNode *root){
	int height=0;
	return _isBalanced(root,&height);
}

int depth(TreeNode *root){//屌丝方法
	if(!root)return 0;
	return max(depth(root->left),depth(root->right))+1;
}

bool isBalanced(TreeNode *root) {
	if(!root)return true;
	if(abs(depth(root->left)-depth(root->right))>1)
		return false;
	return isBalanced(root->left) && isBalanced(root->right);
}