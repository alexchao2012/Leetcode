#include"stage3.h"
/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:

[
  [15,7]
  [9,20],
  [3],
]
*/
void getGivenLevel(TreeNode *root,int level,vector<int> &ret){
	//不要返回局部变量，否则在用完后会被新调用的覆盖
	if(!root)return;
	if(level==1)
		ret.push_back(root->val);
	else if(level>1){
		getGivenLevel(root->left,level-1,ret);
		getGivenLevel(root->right,level-1,ret);
	}
}
vector<vector<int> > levelOrderBottom(TreeNode *root){
	vector<vector<int> > ret;
	if(!root)return ret;

	int height=maxDepth(root);

	for(int i=height;i>0;--i){
		vector<int> temp;
		getGivenLevel(root,i,temp);
		ret.push_back(temp);
	}

	return ret;
}

vector<vector<int> > levelOrderBottom2(TreeNode *root) {

    vector<vector<int> > ret;
	if(!root)return ret;

	queue<TreeNode *> Q;
	TreeNode *dummy=new TreeNode(INT_MIN);
	vector<int>temp;
	Q.push(root);
	Q.push(dummy);

	while(true){
		if(Q.front()->val==dummy->val){
			ret.insert(ret.begin(),temp);
			temp.clear();
			Q.pop();
			if(Q.empty())break;
			Q.push(dummy);
		}
		TreeNode *front=Q.front();
        Q.pop();
		temp.push_back(front->val);
		if(front->left)Q.push(front->left);
		if(front->right)Q.push(front->right);
	}

	return ret;
}

