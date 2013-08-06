#include<iostream>

using namespace std;

inline static int max(int x,int y){
	return x > y ? x : y;
}

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int _x):val(_x),left(NULL),right(NULL){}
};

int maxSubtreeSum(TreeNode *root,int *curSum){
	*curSum = 0;
	if(root == NULL) { return 0;}

	int lMax = maxSubtreeSum(root->left,curSum);
	int lSum = *curSum;

	int rMax = maxSubtreeSum(root->right,curSum);
	int rSum = *curSum;

	*curSum = lSum + rSum + root->val;

	return max(*curSum,max(lMax,rMax));
}

int main(){
	TreeNode t1(1),t2(-2),t3(3),t4(4);
	t1.left = &t2;
	t1.right = &t3;
	t3.left = &t4;

	int curSum;
	cout<< maxSubtreeSum(&t1,&curSum)<<endl;

	return 0;
}
