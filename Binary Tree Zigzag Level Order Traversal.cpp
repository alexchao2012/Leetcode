#include"stage3.h"
/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]
*/
vector<vector<int> > zigzagLevelOrder(TreeNode *root) {//ͬlevelOrder

    vector<vector<int> > ret;
	if(!root)return ret;

	queue<TreeNode *> Q;
	TreeNode *dummy=new TreeNode(INT_MIN);
	vector<int>temp;
	Q.push(root);
	Q.push(dummy);
	int cnt=1;

	while(true){
		if(Q.front()->val==dummy->val){
			ret.push_back(temp);
			temp.clear();
			++cnt;
			Q.pop();
			if(Q.empty())break;
			Q.push(dummy);
		}
		TreeNode *front=Q.front();
        Q.pop();
		if(cnt%2!=0)
			temp.push_back(front->val);
		else
			temp.insert(temp.begin(),front->val);
		if(front->left)Q.push(front->left);
		if(front->right)Q.push(front->right);
	}

	return ret;
}