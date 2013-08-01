#include"stage2.h"

int minPathSum(vector<vector<int> > &grid) {//dp
	int ret=0;
    if(grid.size()==0 || grid[0].size()==0)return ret;

	int m=grid.size(),n=grid[0].size();
	int **dp=new int*[m];
	for(int i=0;i<m;++i)
		dp[i]=new int[n];

	dp[0][0]=grid[0][0];
	for(int i=1;i<n;++i)
		dp[0][i]=dp[0][i-1]+grid[0][i];
	for(int j=1;j<m;++j)
		dp[j][0]=dp[j-1][0]+grid[j][0];

	for(int i=1;i<m;++i)
		for(int j=1;j<n;++j)
			dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];

	ret=dp[m-1][n-1];
	
	for(int i=0;i<m;++i)
		delete [] dp[i];
	delete [] dp;

	return ret;
}


