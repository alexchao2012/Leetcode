#include"stage2.h"
/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/
int removeDuplicates(int A[], int n) {
    if(NULL==A || n<=0)return 0;
	if(n==1)return n;

	int slow=1,fast=1;
	bool flag=true;

	while(fast<n){
		if(A[fast]!=A[slow]){
			A[slow++]=A[fast];
			flag=true;
		}
		else if(flag){
			A[slow++]=A[fast];
			flag=false;
		}
		++fast;
	}
	return slow;
}