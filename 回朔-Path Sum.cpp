#include"stage3.h"
/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/
bool hasPathSum(TreeNode *root, int sum) {
	if(!root)return false;
	sum-=root->val;//必须先减去，在进入下次深度搜索

	if(sum==0 && !root->left && !root->right)return true;

	return hasPathSum(root->left,sum) || hasPathSum(root->right,sum);
}