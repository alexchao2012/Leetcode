#include"stage3.h"

int printGivenLevel(TreeNode *root,int level){
	if(!root)return;
	if(level==1)
		printf("%d",root->val);
	else if(level>1){
		printGivenLevel(root->left,level-1);
		printGivenLevel(root->right,level-1);
	}
}