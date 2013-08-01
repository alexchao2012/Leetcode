#include"stage3.h"
/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/
TreeNode *build2(vector<int> &num,int left,int right){
	if(left>right)return NULL;
	int mid=left+((right-left)>>1);

	TreeNode *root=new TreeNode(num[mid]);

	root->left=build2(num,left,mid-1);
	root->right=build2(num,mid+1,right);

	return root;
}

TreeNode *sortedArrayToBST(vector<int> &num) {
	if(num.size()==0)return NULL;
	return build2(num,0,num.size()-1);
}