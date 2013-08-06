#include"stage2.h"
/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/
bool binarySearch(vector<vector<int> > &matrix,int target,int row){
    if(row<0 || row>=matrix.size())return false;
	int n=matrix[0].size();
	int left=0,right=n-1;
	while(left<=right){
		int mid=left+((right-left)>>1);
		if(matrix[row][mid]==target)
			return true;
		if(matrix[row][mid]<target)
			left=mid+1;
		else
			right=mid-1;
	}
	return false;
}

bool searchMatrix1(vector<vector<int>>&matrix, int target){//找非严格下届
	if(matrix.size()==0 || matrix[0].size()==0)return false;
	int m=matrix.size(),n=matrix[0].size();
	if(matrix[0][0]>target || matrix[m-1][n-1]<target)return false;

	//(target>matrix[m-1][0])return binarySearch(matrix,target,m- 1);
	int left=0,right=m-1;
	while(left<right){
		int mid=left+((right-left+1)>>1);//这里一定注意找非严格下届时，要向上取整，否则会爬不过坡
		if(matrix[mid][0]<=target)
			left=mid;
		else
			right=mid-1;
	}
	return binarySearch(matrix,target,left);
}

bool searchMatrix2(vector<vector<int>>&matrix, int target){//找严格上届，一定注意是严格上届
	if(matrix.size()==0 || matrix[0].size()==0)return false;
	int m=matrix.size(),n=matrix[0].size();
	if(matrix[0][0]>target || matrix[m-1][n-1]<target)return false;

	if(target>=matrix[m-1][0])return binarySearch(matrix,target,m- 1);//这里的比较必须是大于等于，这样才可以保证取得是严格上届
	int left=0,right=m-1;
	while(left<right){
		int mid=left+((right-left)>>1);
        if(matrix[mid][0]==target)return true;
		if(matrix[mid][0]>target)
			right=mid;
		else
			left=mid+1;
	}
	return binarySearch(matrix,target,right-1);
}