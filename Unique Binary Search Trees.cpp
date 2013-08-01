#include"stage3.h"
/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
int numTrees(int n) {//树形dp问题,边界不易控制时，直接造一个合理边界，这是真的懂
	vector<int> num(n+1, 0); 
	num[0] = 1; 
	if(n > 0) num[1] = 1; 
	for(int i = 2; i < n+1; i++) 
		for(int j = 0; j < i; j++) 
			num[i] += num[j]*num[i-j-1]; 
	return num[n]; 
}
