#include"stage3.h"
/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
*/
int maxContainRoot(TreeNode *root, int& maxSoFar){ 
	if (root == NULL) return 0;

	int leftMax = maxContainRoot(root->left,maxSoFar); 
	int rightMax = maxContainRoot(root->right,maxSoFar); 

	int m = root->val; 
	int longerLeg = max(leftMax,rightMax);

	int result = max(m, m+longerLeg); 

	int maxPath = m; 
	maxPath = max(maxPath,maxPath+leftMax); 
	maxPath = max(maxPath,maxPath+rightMax); 
	
	maxSoFar = max(maxSoFar, maxPath); 
	return result; 
}
int maxPathSum(TreeNode *root) { 
	int maxSoFar= root->val; 
	maxContainRoot(root, maxSoFar); 
	return maxSoFar;
}



int calLen(TreeNode *root, int &len)
{
    if (root == NULL)
    {
        len = 0;
        return 0;
    }
         
    if (root->left == NULL && root->right == NULL)
    {
        len = root->val;
        return root->val;
    }
         
    int leftPath, rightPath;
    int leftLen;
    if (root->left)
        leftLen = calLen(root->left, leftPath);
    else
    {
        leftLen = INT_MIN;
        leftPath = 0;
    }
         
    int rightLen;
    if (root->right)
        rightLen = calLen(root->right, rightPath);
    else
    {
        rightLen = INT_MIN;
        rightPath = 0;
    }
         
    len = max(max(leftPath, rightPath) + root->val, root->val);
    int maxLen = max(root->val, max(leftPath + rightPath + root->val, 
        max(leftPath + root->val, rightPath + root->val)));
         
    return max(max(leftLen, rightLen), maxLen);
}
     
int maxPathSum1(TreeNode *root) {//树形DP 求最大和
    int len;
    return calLen(root, len);
}


int diameter(TreeNode *root,int *height){//树形DP 求树的直径
	int lh=0,rh=0;

	int lDiameter=0,rDiameter=0;

	if(root==NULL){
		*height=0;
		return 0;
	}
		
	lDiameter=diameter(root->left,&lh);
	rDiameter=diameter(root->right,&rh);

	*height=max(lh,rh)+1;

	return max(lh+rh+1,max(lDiameter,rDiameter));
}