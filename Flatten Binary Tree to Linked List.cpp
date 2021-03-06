#include"stage3.h"
/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
*/
TreeNode* mostRight(TreeNode* t){ 
	while(t&&t->right) t = t->right; 
	return t; 
}
void flatten(TreeNode *root) { 
	TreeNode* n = root; 
	if(!n) return; 
	while(n){
		if(n->left){
			TreeNode* mr = mostRight(n->left);
			mr->right = n->right; 
			n->right = n->left; 
			n->left = NULL; 
		}
		n = n->right; 
	} 
}