#include"stage3.h"
/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/



vector<vector<int> > generate(int numRows) {
	vector<vector<int> > ret;
	vector<int> temp;
	
	for(int row=0;row<numRows;++row){//这里的规律很明显，注意观察
		for(int i=temp.size()-1;i>0;--i)
			temp[i]+=temp[i-1];
		temp.push_back(1);
		ret.push_back(temp);
	}

	return ret;
}