#include"stage3.h"
/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
*/

vector<vector<int> > levelOrder1(TreeNode *root){
	vector<vector<int> > ret;
	if(!root) return ret;

	vector<TreeNode *> buf;
	buf.push_back(root);

	while(!buf.empty()){
		vector<int> solution;
		vector<TreeNode *> tmp;

		for(int i=0;i<buf.size();++i){
			solution.push_back(buf[i]->val);

			if(buf[i]->left)
				tmp.push_back(buf[i]->left);
			if(buf[i]->right)
				tmp.push_back(buf[i]->right);
		}

		buf=tmp;
		ret.push_back(solution);
	}

	return ret;
}
vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > ret;
	if(!root)return ret;

	queue<TreeNode *> Q;
	TreeNode *dummy=new TreeNode(INT_MIN);
	vector<int>temp;
	Q.push(root);
	Q.push(dummy);

	while(true){
		if(Q.front()->val==dummy->val){
			ret.push_back(temp);
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
