#include<iostream>
#include<cstdio>
using namespace std;

const int SIZE=110;
int M[SIZE][SIZE];

int maxSum(int *A,int n){
	int max=-0xffffff,sum=0;

	for(int i=0;i<n;++i){
		sum=(sum<0?0:sum)+A[i];
		if(sum>max)max=sum;
	}

	return max;
}

int maxSum2D(int n,int M[][SIZE]){
	int ret=INT_MIN;
	int col[SIZE];

	for(int i=0;i<n;++i){
		memset(col,0,sizeof(col));

		for(int j=i;j<n;++j){
			for(int k=0;k<n;++k)
				col[k]+=M[j][k];
			int sum=maxSum(col,n);
			if(sum>ret)ret=sum;
		}
	}

	return ret;
}
