#include"stage3.h"
/*
You are given a string, S, and a list of words, L, that are all of the same
length. Find all starting indices of substring(s) in S that is a concatenation
of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/
vector<int> findSubstring(string S, vector<string> &L) {
	vector<int> ret;
	if(S.empty() || L.empty()) return ret;

	int M=L[0].size(),N=L.size();

	map<string,int> hash,found;
	for(int i=0;i<N;++i)
		hash[L[i]]++;

	for(int i=0;i<=(int)S.size()-M*N;++i){
		found.clear();
		int j=0;
		for( ;j<N;++j){
			string sub=S.substr(i+j*M,M);

			if(hash.find(sub)==hash.end() || ++found[sub]>hash[sub])
				break;
		}
		if(j==N) ret.push_back(i);
	}
	return ret;
}
class Solution {
 private:
     int count[1000];
     int countSize;
     map<string, int> index;
     vector<int> ret;
 public:
     vector<int> findSubstring(string S, vector<string> &L) {
         // Start typing your C/C++ solution below
         // DO NOT write int main() function
         ret.clear();
         if (L.size() == 0)
             return ret;
 
         index.clear();
         countSize = 0;
         for(int i = 0; i < L.size(); i++)
             if (index.count(L[i]) > 0)
                 count[index[L[i]]]++;
             else
             {
                 index[L[i]] = countSize;
                 count[countSize++] = 1;
             }
 
             int step = L[0].size();
 
             vector<int> a;
 
             for(int i = 0; i < step; i++)
             {
                 a.clear();
                 for(int j = i; j < S.size(); j += step)
                 {
                     if (j + step <= S.size())
                     {
                         string s(S, j, step);
                         if (index.count(s) > 0)
                             a.push_back(index[s]);
                         else
                             a.push_back(-1);
                     }
                 }
 
                 int beg = -1;
                 int end = 0;
                 int size = L.size();
                 while(end < a.size())
                 {
                     if (a[end] != -1)
                     {
                         if (count[a[end]] > 0)
                         {
                             if (beg == -1)
                                 beg = end;
                             size--;
                             count[a[end]]--;
                         }
                         else
                         {
                             while(beg < end)
                             {
                                 count[a[beg]]++;
                                 size++;
                                 if (a[beg++] == a[end])
                                     break;
                             }
                             count[a[end]]--;
                             size--;
                         }
                     }
                     else
                     {
                         size = L.size();
                         if (beg != -1)
                         {    
                             for(int i = beg; i < end; i++)
                                 count[a[i]]++;
                         }
                         beg    = -1;
                     }
 
                     end++;
 
                     if (size == 0)
                     {
                         ret.push_back(beg * step + i);
                         size++;
                         count[a[beg]]++;
                         beg++;
                     }
                 }
 
                 if (beg != -1)
                 {
                     for(int i = beg; i < end; i++)
                         count[a[i]]++;
                 }
             }
 
             return ret;
     }
 };