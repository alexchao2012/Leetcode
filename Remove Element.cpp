#include"head.h"
/*
Given an array and a value, remove all instances of 
that value in place and return the new length.
The order of elements can be changed. It doesn't matter
what you leave beyond the new length.
*/
int removeElement(int A[], int n, int elem){
	if(n<=0)
		return 0;//零指的是长度
	int i,j;
	j=-1;
	for(i=0;i<n;++i)
		if(A[i]!=elem)
			A[++j]=A[i];
	return j+1;
}
