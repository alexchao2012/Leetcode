#include"stage3.h"
/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/
vector<int> getRow(int rowIndex) {
	vector<int>ret;

	for(int i=0;i<=rowIndex;++i){
		for(int j=ret.size()-1;j>0;--j)
			ret[j]+=ret[j-1];
		ret.push_back(1);
	}
	return ret;
}

