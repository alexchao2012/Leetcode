#include"stage2.h"

/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n)time and uses constant space.
*/

int firstMissingPositive(int A[], int n){
    if(0==n || NULL==A)
		return 1;

	for(int i=0;i<n;++i)
        A[i]=(A[i]<0)?0:A[i];

	for(int i=0;i<n;++i){
		int idx=abs(A[i])-1;

		if(idx>=0 && idx<n){
			if(A[idx]>0)
				A[idx]*=-1;
			else if(A[idx]==0)//这里极容易写错，要理解怎么映射
				A[idx]=-1*(idx+1);
		}
	}

	for(int i=0;i<n;++i)
		if(A[i]>=0)return i+1;

	return n+1;
}