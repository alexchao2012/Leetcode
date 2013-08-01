#include"stage3.h"
/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:

    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/
bool symmetric(TreeNode *p,TreeNode *q){//�ݹ鷽ʽ
    if(!p && !q)return true;
	if(!p || !q)return false;

	return p->val==q->val && symmetric(p->left,q->right) && symmetric(p->right,q->left);
}

bool isSymmetric(TreeNode *root) {
	return symmetric(root,root);
}
