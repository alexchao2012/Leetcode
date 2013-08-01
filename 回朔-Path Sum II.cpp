#include"stage3.h"
/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]
*/
void dfs(TreeNode *root,int sum,vector<int> path,vector<vector<int> > &ret){
	//一定注意这里不能乱用引用，如path如果使用引用那就报错了，因为那个是个局部变量，不应该让他出了他的生命周期
    if(!root)return;

	path.push_back(root->val);

	if(sum==root->val && !root->left && !root->right){//这一句话需要变通.......
		ret.push_back(path);
		return;
	}	

	dfs(root->left,sum-root->val,path,ret);
	dfs(root->right,sum-root->val,path,ret);
}
vector<vector<int> > pathSum(TreeNode *root,int sum){
	vector<vector<int> >ret;
	if(!root)return ret;

	vector<int> path;

	dfs(root,sum,path,ret);

	return ret;
}