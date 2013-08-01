#include"stage3.h"
/*
Given an unsorted array of integers, find the length
of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. 
Return its length: 4.

Your algorithm should run in O(n) complexity.
*/
 int longestConsecutive(vector<int> &num) {
     set<int> set;

	 for(int i=0;i<num.size();++i)
		 set.insert(num[i]);

	 int maxLen=INT_MIN;

	 while(!set.empty()){
		 int count=0;

		 int pivot=*set.begin();
		 set.erase(pivot);
		 ++count;

		 int i=1;
		 while(set.count(pivot+i)!=0){
			 set.erase(pivot+i);
			 ++count;
			 ++i;
		 }

		 i=-1;
		 while(set.count(pivot+i)!=0){
			 set.erase(pivot+i);
			 ++count;
			 --i;
		 }

		 if(count>maxLen)
			 maxLen=count;
	 }

	 return maxLen;
 }