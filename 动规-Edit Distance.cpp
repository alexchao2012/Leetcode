#include"stage2.h"
/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

#include"head.h"

static int min(int x,int y,int z){
	int smallest=x;
	if(y<smallest)
		smallest=y;
	return z<smallest?z:smallest;
}

int minDistance(string word1, string word2) {
    if(word1.size()==0)return word2.size();
	if(word2.size()==0)return word1.size();

	int n1=word1.size(),n2=word2.size();
	int **dp=new int*[n1+1];
	for(int i=0;i<=n1;++i)
		dp[i]=new int[n2+1];

	dp[0][0]=0;
	for(int i=1;i<=n1;++i)
		dp[i][0]=i;
	for(int j=1;j<=n2;++j)
		dp[0][j]=j;

	for(int i=1;i<=n1;++i)
		for(int j=1;j<=n2;++j){
			dp[i][j]=INT_MAX;//这里注意，赋一个极小值。
			if(word1[i-1]==word2[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1;
		}
	int ret=dp[n1][n2];
	
	for(int i=0;i<=n1;++i)
		delete [] dp[i];
	delete [] dp;

	return ret;
}