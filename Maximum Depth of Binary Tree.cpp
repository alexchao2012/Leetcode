#include"stage3.h"
/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/
int maxDepth(TreeNode *root) {
	if(!root)return 0;
	if(!root->left && !root->right)return 1;

	return 1+max(maxDepth(root->left),maxDepth(root->right));
}
	