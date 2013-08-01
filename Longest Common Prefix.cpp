#include"head.h"

string longestCommonPrefix(vector<string> &strs){
	int n=strs.size();
	int i=0;
	string res;
	int curIndex=0;
	char tester;
	for(;i<strs.size();++i){
		string &s=strs[i];

		if(curIndex>=s.size())
			return res;
		if(i==0)
			tester=s[curIndex];
		else if(tester!=s[curIndex])
			return res;
		if(i==strs.size()-1){
			res.push_back(tester);
			++curIndex;
			i=-1;
		}
	}
	return res;
}
