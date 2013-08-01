#include"stage3.h"
/*
Given a binary tree containing digits from 0-9 only, 
each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which 
represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/
int getInteger(vector<int> path){
	int beg=0,ans=0;

	while(path[beg]==0 && beg<path.size())
		++beg;

	for(;beg<path.size();++beg)
		ans=10*ans+path[beg];

	return ans;
}

void dfs(TreeNode *root,vector<int> path,int &totalSum){
	path.push_back(root->val);

	if(!root)return;

	if(!root->left && !root->right){
		int cur=getInteger(path);
		totalSum+=cur;
	}

	if(root->left)dfs(root->left,path,totalSum);
	if(root->right)dfs(root->right,path,totalSum);

	path.pop_back();
}

int sumNumbers(TreeNode *root) {
	int totalSum=0;
	if(!root)return totalSum;

	vector<int> path;
	dfs(root,path,totalSum);

	return totalSum;
}