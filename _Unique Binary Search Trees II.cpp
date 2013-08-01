#include"stage3.h"
/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/
vector<TreeNode *> generate(int beg, int end){ 
	vector<TreeNode* > ret; 
	if (beg > end){ 
		ret.push_back(NULL); 
		return ret; 
	}
	for(int i = beg; i <= end; i++){ 
		vector<TreeNode*> leftTree = generate(beg, i - 1); 
		vector<TreeNode*> rightTree = generate(i + 1, end); 
		for(int j = 0; j < leftTree.size(); j++) 
			for(int k = 0; k < rightTree.size(); k++){ 
				TreeNode *node = new TreeNode(i + 1); 
				ret.push_back(node); 
				node->left = leftTree[j]; 
				node->right = rightTree[k]; 
			} 
	}
	return ret; 
}
vector<TreeNode *> generateTrees(int n) { 
	return generate(0, n - 1); 
}