#include"stage2.h"


void findOut(int idx,int *index,int &cnt,int n){
	if(idx==n)cnt++;
	int j,k;
	for(j=0;j<n;++j){
		for(k=0;k<idx;++k)
			if(index[k]==j || (idx-k==j-index[k]) || (k-idx==j-index[k]))
				break;
		if(k==idx){
			index[idx]=j;
			findOut(idx+1,index,cnt,n);
		}
	}
}
int totalNQueens(int n) {
	if(n<=3 && n!=1)return 0;//八皇后的含有1*1的矩阵时是可以求解的！
	int cnt=0;
	int *index=new int[n];
	findOut(0,index,cnt,n);
	delete [] index;
	return cnt;
}

