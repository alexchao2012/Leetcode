#include"stage3.h"
/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/
void midOrder(vector<int>& ret, TreeNode* root)  
{  
    if(NULL != root)  
    {  
        midOrder(ret, root->left);  
        ret.push_back(root->val);  
        midOrder(ret, root->right);  
    }  
}
bool isValidBST2(TreeNode *root) {//一定注意，满足左小右大的不一定是BST，必须满足所有左子树比根小，和所有右子树比根大  
    vector<int> orderedList;  
    midOrder(orderedList, root);  
    for(int i = 1; i < orderedList.size(); ++i)  
        if(orderedList[i] <= orderedList[i-1])  
            return false;  
    return true;  
}  
  


bool checkBST(TreeNode *root,int min,int max){
	if(!root)return true;
	if(root->val>min && root->val<max)
		return checkBST(root->left,min,root->val) && checkBST(root->right,root->val,max);
	return false;
}
bool isValidBST(TreeNode *root){
	return checkBST(root,INT_MIN,INT_MAX);
}