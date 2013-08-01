#include"stage2.h"
/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
void com(int n,int k,int l,int pos,vector<vector<int> > &ret,vector<int> &record){
	if(l>k)return;
	if(l==k){
		ret.push_back(record);
		return;
	}
	for(int i=pos;i<n;++i){
		record[l]=i+1;
		com(n,k,l+1,i+1,ret,record);
	}
}

vector<vector<int> > combine(int n, int k) {
	vector<vector<int> > ret;
	if(n<=0 || k<=0)return ret;
	vector<int> record(k);
	com(n,k,0,0,ret,record);
	return ret;
}
void dummy(int A[],int n){
	for(int i=0;i<n-1;++i)
		cout<<A[i]<<' ';
	cout<<A[n-1]<<endl;
}

void com2(int *A,int n,int k,int leng,int pos,int *rcd){
	if(leng>k)return;
	if(leng==k){dummy(rcd,k);return;}
	for(int i=pos;i<n;++i){
		rcd[leng]=A[i];
		com2(A,n,k,i+1,i+1,rcd);
		while(A[i]==A[i+1] && i+1<n)
			++i;
	}
}
void combine2(int A[],int n,int k){
	if(A==NULL || n<=0 || k<=0)return;

	int *rcd=new int[k];
	com2(A,n,k,0,0,rcd);
	delete [] rcd;
}