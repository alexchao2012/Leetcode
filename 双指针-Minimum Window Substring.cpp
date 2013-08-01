#include"stage2.h"
/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/
//类似于最短摘要
string minWindow(string S, string T) {
	int need[256] = {0}; 
	for(int i = 0; i < T.size(); i++) 
		need[T[i]]++; 
	int found[256] = {0}; 

	int count = 0; 
	int minLen = S.size()+1; 
	int minBegin = 0; 

	for(int begin = 0, end = 0; end < S.size(); ++end){ 
		char ch = S[end]; 

		if(need[ch] == 0) 
			continue; 

		if(++found[ch] <= need[ch])
			count++; 

		if(count == T.size()){
			while(need[S[begin]] == 0 || found[S[begin]] > need[S[begin]]){ 
				if(found[S[begin]] > need[S[begin]]) 
					found[S[begin]]--;
				begin++;
			}

			int leng = end - begin + 1; 
			if(leng < minLen){
				minLen = leng;
				minBegin = begin; 
			} 
		} 
	}

	return minLen > S.size()?"":S.substr(minBegin,minLen);
}
