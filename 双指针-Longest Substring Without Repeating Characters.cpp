#include"stage3.h"
/*
Given a string, find the length of the longest substring without repeating 
characters. For example, the longest substring without repeating letters for
"abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring 
is "b", with the length of 1.
*/
int lengthOfLongestSubstring(string s) {
	if(s.empty()) return 0;

	int maxLeng=INT_MIN,beg=0,end=0;
	bool hash[256]={false};

	for(;end<s.size();++end){
		char ch=s[end];

		if(hash[ch]){
			maxLeng=max(maxLeng,end-beg);

			while(s[beg]!=ch){
				hash[s[beg]]=false;
				++beg;
			}

			++beg;
		}
		else
			hash[ch]=true;
	}

	return max(maxLeng,end-beg);
}