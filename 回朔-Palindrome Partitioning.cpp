#include"stage3.h"
/*
Given a string s, partition s such that every substring of the 
partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/
static bool isPalindrome(string s,int left,int right){
	while(left<right){
		if(s[left]!=s[right])
			return false;
		++left;
		--right;
	}

	return true;
}

void dfs(string &s,int start,vector<string> &curSubStrs,vector<vector<string> > &ret){
	if(start==s.size()){
		ret.push_back(curSubStrs);
		return;
	}

	for(int i=start;i<s.size();++i){
		if(isPalindrome(s,start,i)){
			curSubStrs.push_back(s.substr(start,i-start+1));
			dfs(s,i+1,curSubStrs,ret);
			curSubStrs.pop_back();
		}
	}
}

vector<vector<string>> partition(string s) {
	vector<vector<string> > ret;
	if(s.size()==0)return ret;

	vector<string> curSubStrs;
	dfs(s,0,curSubStrs,ret);

	return ret;
}