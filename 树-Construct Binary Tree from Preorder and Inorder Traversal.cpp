#include"stage3.h"
/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/
TreeNode *build(vector<int> &pre,int pos,vector<int> &in,int left,int right){
	if(left>right)return NULL;

	TreeNode *root=new TreeNode(pre[pos]);
	int pivot=left;
	while(pivot<right){
		if(in[pivot]==pre[pos])
			break;
		++pivot;
	}

	//int offset=pivot+1-left;//这个是用来计算偏移量的！！！！
	root->left=build(pre,pos+1,in,left,pivot-1);
	root->right=build(pre,pos+pivot+1-left,in,pivot+1,right);

	return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
	return build(preorder,0,inorder,0,inorder.size()-1);
}