#include"head.h"
/*
Given a sorted array, remove the duplicates in place such that 
each element appear only once and return the new length.
Do not allocate extra space for another array,you must do this 
in place with constant memory.
For example,
Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2].
*/
int removeDuplicates(int A[], int n){
	assert(n>=0);
	if(n<=1)
		return n;

	int i,j;
	i=j=0;
	for(++i;i<n;++i)
		if(A[i]!=A[j])
			A[++j]=A[i];
	return j+1;
}
