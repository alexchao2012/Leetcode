#include"stage2.h"

/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
//此处使用了第0行和第0列作为storage来存储其他位置的信息，最后将0行，0列根据是否为0做相应的修改
void setZeroes(vector<vector<int> > &matrix) {
	if(matrix.size()==0 || matrix[0].size()==0)return;
	int m=matrix.size(),n=matrix[0].size();

	bool isRowZero=false,isColZero=false;
	for(int i=0;i<m;++i)
		if(matrix[i][0]==0){
			isRowZero=true;
			break;
		}
	for(int j=0;j<n;++j)
		if(matrix[0][j]==0){
			isColZero=true;
			break;
		}

	for(int i=1;i<m;++i)
		for(int j=1;j<n;++j)
			if(matrix[i][j]==0){
				matrix[i][0]=0;
				matrix[0][j]=0;
			}
	for(int i=1;i<m;++i)
		for(int j=1;j<n;++j)
			if(matrix[i][0]==0 || matrix[0][j]==0)
				matrix[i][j]=0;

	if(isRowZero)
		for(int i=0;i<m;++i)
			matrix[i][0]=0;
	if(isColZero)
		for(int j=0;j<n;++j)
			matrix[0][j]=0;
}