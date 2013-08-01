#include"stage3.h"
/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/
//三种方法，1.递归 2.队列 3.循环同层打印
//1.
void inOrder(TreeNode *root,vector<int> &ret){
	if(root && root->val!='#'){
		
		if(root->left && root->left->val!='#')inOrder(root->left,ret);
		ret.push_back(root->val);
		if(root->right && root->right->val!='#')inOrder(root->right,ret);
	}
}
vector<int> inorderTraversal2(TreeNode *root) {
	vector<int> ret;
	inOrder(root,ret);
	return ret;
}

void preOrder(TreeNode *root,vector<int> &ret){
	if(root && root->val!='#'){
		ret.push_back(root->val);
		if(root->left && root->left->val!='#')preOrder(root->left,ret);
		if(root->right && root->right->val!='#')preOrder(root->right,ret);
	}
}

vector<int> preorderTraversal(TreeNode *root){
	vector<int>ret;
	preOrder(root,ret);
	return ret;
}

//2.
vector<int> inorderTraversal(TreeNode *root){
	vector<int> ret;
	if(!root || root->val=='#')return ret;

	stack<TreeNode *> st;
	TreeNode *ptr=root;

	while(ptr || !st.empty()){
		if(ptr && ptr->val!='#'){
			st.push(ptr);
			ptr=ptr->left;
		}
		else{
			TreeNode *top=st.top();
			ret.push_back(top->val);
			st.pop();
			ptr=top->right;
		}
	}
	return ret;
}

//3.
void inorderTraversal3(TreeNode *root){
	int height=maxDepth(root);
	for(int i=1;i<height;++i)
		printGivenLevel(root,i);
}