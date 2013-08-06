#include"stage2.h"
/*A robot is located at the top-left corner of a m x n grid
(marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid 
(marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.*/

//回朔的方式，大数据超时
void search(int row,int col,int m,int n,int &ret){
	if(row==m-1 && col==n-1)
		++ret;
	else{
		if(row<m)search(row+1,col,m,n,ret);
		if(col<n)search(row,col+1,m,n,ret);
	}
}

int uniquePaths2(int m, int n) {
	assert(m>0 && n>0);
	int ret=0;
	search(0,0,m,n,ret);
	return ret;
}

int uniquePaths(int m, int n) { // 漂亮
	const int M_MAX = 100; 
	const int N_MAX = 100;
	
	int mat[M_MAX+2][N_MAX+2] = {0}; 
	mat[m][n+1] = 1; 
	
	for (int r = m; r >= 1; r--) 
		for (int c = n; c >= 1; c--) 
			mat[r][c] = mat[r+1][c] + mat[r][c+1]; 
	
	return mat[1][1];
}

int uniquePaths1(int m,int n){//dp，O(n^2) bingo
	assert(m>0 && n>0);

	int **dp=new int*[m];
	for(int i=0;i<m;++i)
		dp[i]=new int[n];

	for(int i=0;i<n;++i)
		dp[m-1][i]=1;
	for(int i=0;i<m;++i)
		dp[i][n-1]=1;

	for(int i=m-2;i>=0;--i)
		for(int j=n-2;j>=0;--j)
			dp[i][j]=dp[i+1][j]+dp[i][j+1];

	int ret=dp[0][0];
	
	for(int i=0;i<m;++i)
		delete [] dp[i];
	delete [] dp;

	return ret;
}
