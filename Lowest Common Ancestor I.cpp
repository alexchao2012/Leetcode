#include"stage3.h"
/*
	Using a bottom-up approach, we can improve over the top-down approach
by avoiding traversing the same nodes over and over again.

	We traverse from the bottom, and once we reach a node which matches 
one of the two nodes, we pass it up to its parent. The parent would 
then test its left and right subtree if each contain one of the two 
nodes. If yes, then the parent must be the LCA and we pass its parent 
up to the root. If not, we pass the lower node which contains either 
one of the two nodes (if the left or right subtree contains either p or q), 
or NULL (if both the left and right subtree does not contain either p or q)
up.
*/
TreeNode *LCA1(TreeNode *root,TreeNode *p,TreeNode *q){//O(n) 效率高的树形DP
	if(!root)return NULL;
	if(root==p || root==q)return root;

	TreeNode *L=LCA1(root->left,p,q);
	TreeNode *R=LCA1(root->right,p,q);

	if(L && R)return root;
	return L?L:R;
}

int countMatches(TreeNode *root,TreeNode *p,TreeNode *q){
	if(!root)return 0;

	int matches=countMatches(root->left,p,q)+countMatches(root->right,p,q);

	if(root == p || root==q)
		return 1+matches;
	else
		return matches;
}


TreeNode *LCA(TreeNode *root,TreeNode *p,TreeNode *q){//O(n^2)算法，top-bottom
	if(!root || !p || !q)return NULL;
	if(root==p || root==q)return root;

	int totalMatches=countMatches(root->left,p,q);
	if(totalMatches==1)
		return root;
	else if(totalMatches==2)
		return LCA(root->left,p,q);
	else
		return LCA(root->right,p,q);
}

//int main(){
//	TreeNode t1(1),t2(2),t3(3),t4(4),t5(5),t6(6);
//	t1.left=&t2,t1.right=&t3;
//	t2.left=&t4,t2.right=&t5;
//	t3.left=&t6;
//
//	TreeNode *ret=LCA1(&t1,&t5,&t4);
//	cout<<ret->val;
//}