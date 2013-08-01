#include"stage2.h"
/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/
typedef multimap<string,string>::iterator iter;
 vector<string> anagrams(vector<string> &strs) {
	 vector<string> ret;
	 if(strs.size()<=1)return ret;

	 multimap<string,string> mm;
	 for(int i=0;i<strs.size();++i){
		 string tmp=strs[i];
		 sort(tmp.begin(),tmp.end());
		 mm.insert(make_pair(tmp,strs[i]));
	 }

	 for(multimap<string,string>::iterator itr=mm.begin();itr!=mm.end();++itr){
		iter i1=mm.lower_bound(itr->first),i2=mm.upper_bound(itr->first);
		int cnt=0;
		for(iter i=i1;i!=i2;++i)
			++cnt;
		if(cnt>1){
			for(iter i=i1;i!=i2;++i){
				ret.push_back(i->second);
				++itr;
			}
		--itr;
		}
	
	 }
	 return ret;
 }