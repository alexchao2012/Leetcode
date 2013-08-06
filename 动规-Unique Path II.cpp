#include"stage2.h"

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    int ret=0;
	int m=obstacleGrid.size();
	if(m==0)return ret;
	int n=obstacleGrid[0].size();
	if(n==0)return ret;

	int **dp=new int*[m];
	for(int i=0;i<m;++i)
		dp[i]=new int[n];

	for(int i=n-1;i>=0;--i)
		if(obstacleGrid[m-1][i])
			while(i>=0){
				dp[m-1][i]=0;
				--i;
			}
		else
			dp[m-1][i]=1;

	for(int i=m-1;i>=0;--i)
		if(obstacleGrid[i][n-1])
			while(i>=0){
				dp[i][n-1]=0;
				--i;
			}
		else
			dp[i][n-1]=1;

	for(int i=m-2;i>=0;--i)
		for(int j=n-2;j>=0;--j)
			if(obstacleGrid[i][j])
				dp[i][j]=0;
			else
				dp[i][j]=dp[i+1][j]+dp[i][j+1];

	ret=dp[0][0];
	
	for(int i=0;i<m;++i)
		delete [] dp[i];
	delete [] dp;

	return ret;
}