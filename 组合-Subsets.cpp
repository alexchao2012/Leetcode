#include"stage2.h"
/*
Given a set of distinct integers, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
void dfs(vector<int> &S,int pos,vector<int> &path,vector<vector<int> > &ret){
	ret.push_back(path);

	for(int i=pos;i<S.size();++i){
		path.push_back(S[i]);

		dfs(S,i+1,path,ret);

		path.pop_back();

		while(i<S.size()-1 && S[i]==S[i+1])//这句必须有，去除掉重复的组合式子
			++i;
	}
}
 vector<vector<int> > subsets(vector<int> &S) {
	 vector<vector<int> > ret;
	 if(S.size()==0)return ret;

	 sort(S.begin(),S.end());//保证输出集合的规范性
	 vector<int> path;

	 dfs(S,0,path,ret);

	 return ret;
 }