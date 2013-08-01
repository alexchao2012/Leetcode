#include"stage2.h"

void backTrack(int idx,int index[],vector<vector<int> > &ret){
	if(8==idx){
		vector<int> temp;
		for(int i=0;i<8;++i)			
			temp.push_back(index[i]);
		ret.push_back(temp);
	}

	int j,k;
	for(j=0;j<8;++j){
		for(k=0;k<idx;++k)
			if(index[k]==j || idx-k==j-index[k] || k-idx==j-index[k])
				break;
		if(k==idx){
			index[idx]=j;
			backTrack(idx+1,index,ret);
		}
	}
}

vector<vector<int> > eightQueens(){
	vector<vector<int> > ret;
	int *index=new int[8];
	backTrack(0,index,ret);
	delete [] index;
	return ret;
}

void backTrack(int idx,int *index,vector<vector<int> > &ret,int n){
	if(idx==n){
		vector<int> temp;
		for(int i=0;i<n;++i)
			temp.push_back(index[i]);
		ret.push_back(temp);
	}

	int j,k;
	for(j=0;j<n;++j){
		for(k=0;k<idx;++k)
			if(index[k]==j || (idx-k==j-index[k]) || (k-idx==j-index[k]))
				break;
		if(k==idx){
			index[idx]=j;
			backTrack(idx+1,index,ret,n);
		}
	}
}

vector<vector<int> > NQueens(int n){
	vector<vector<int> > ret;
	if(n<=3 && n!=1)return ret;
	int *index=new int[n];
	backTrack(0,index,ret,n);
	delete [] index;
	return ret;
}

void findOut(int idx,int *index,vector<vector<string> > &ret,int n){
	if(idx==n){
		vector<string> temp;
		
		for(int i=0;i<n;++i){
			string s(n,'.');
			s[index[i]]='Q';
			temp.push_back(s);
		}
		ret.push_back(temp);
	}
	
	int j,k;
	for(j=0;j<n;++j){
		for(k=0;k<idx;++k)
			if(index[k]==j || (idx-k==j-index[k]) || (k-idx==j-index[k]))
				break;
		if(k==idx){
			index[idx]=j;
			findOut(idx+1,index,ret,n);
		}
	}
}
vector<vector<string> > solveNQueens(int n){
	vector<vector<string> > ret;
	if(n<=3 && n!=1)return ret;//八皇后的含有1*1的矩阵时是可以求解的！
	int *index=new int[n];
	findOut(0,index,ret,n);
	delete [] index;
	return ret;
}
