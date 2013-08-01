#include"stage3.h"
/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/
TreeNode *build2(vector<int> &post,int pos,vector<int> &in,int left,int right){
	if(left>right)return NULL;

	TreeNode *root=new TreeNode(post[pos]);
	int pivot=left;
	while(pivot<=right){
		if(in[pivot]==post[pos])
			break;
		++pivot;
	}

	root->right=build2(post,pos-1,in,pivot+1,right);
	root->left=build2(post,pos+pivot-1-right,in,left,pivot-1);
	
	return root;
}

TreeNode *buildTree2(vector<int> &inorder, vector<int> &postorder) {
	return build2(postorder,postorder.size()-1,inorder,0,inorder.size()-1);
}