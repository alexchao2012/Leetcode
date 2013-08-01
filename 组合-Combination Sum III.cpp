#include"stage2.h"

void backTrack(int sum,int n,vector<int> &temp){
	if(sum>n)return;
	if(sum==n){
		for(int i=0;i<temp.size()-1;++i)
			cout<<temp[i];
		cout<<temp[temp.size()-1]<<endl;
		return;
	}

	for(int i=1;i<=n;++i){
		temp.push_back(i);
		backTrack(sum+i,n,temp);
		temp.pop_back();
	}
}
void combinationSum11(int n){
	assert(n>0);
	vector<int> temp;
	backTrack(0,n,temp);
}