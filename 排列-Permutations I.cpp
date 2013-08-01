#include"stage2.h"
/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/
void dfs(vector<int> &num,vector<bool> &used,vector<int> path,vector<vector<int> > &ret){
	if(path.size() == num.size()){
		ret.push_back(path);
		return;
	}

	for(int i=0;i<num.size();++i){
		if(!used[i]){
			used[i]=true;
			path.push_back(num[i]);

			dfs(num,used,path,ret);

			path.pop_back();
			used[i]=false;
		}
	}
}
vector<vector<int> > permute(vector<int> &num) {
	vector<vector<int> > ret;
	if(num.empty()) return ret;

	vector<bool> used(num.size(),false);
	vector<int> path;

	dfs(num,used,path,ret);

	return ret;
}

vector<int> nextPermutation2(vector<int> num){
	vector<int> ret;
	if(num.size()<=1)return num;
	int n=num.size(),i=n-2;
	while(i>=0 && num[i]>num[i+1])
		--i;
	if(i>=0){
		int j=n-1;
		while(num[i]>num[j])
			--j;
		swap(num[i],num[j]);
		reverse(num.begin()+i+1,num.end());
		return num;
	}
	else{
	reverse(num.begin(),num.end());
	return num;
	}
}
vector<vector<int> > permute(vector<int> &num) {
	vector<vector<int> > ret;
	if(num.size()<=1){
		ret.push_back(num);
		return ret;
	}
	ret.push_back(num);
	int n=num.size();
	int cnt=n;
	for(int i=n-1;i>0;--i)
		cnt*=i;
	int i=1;
	while(i<cnt){
		vector<int> temp=nextPermutation2(num);
		ret.push_back(temp);
		num=temp;
		++i;
	}
	return ret;
}
