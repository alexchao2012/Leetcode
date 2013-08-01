#include"stage2.h"
/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/
bool search(int A[], int n, int target) {
	if(NULL==A || n<=0)return false;
	int left=0,right=n-1;
	while(left<=right){
		int mid=left+((right-left)>>1);

		if(A[mid]==target)return true;

		if(A[mid]>A[right])
			if(A[left]<=target && A[mid]>target)
				right=mid-1;
			else left=mid+1;
		else if(A[mid]<A[right])
			if(A[mid]<target && A[right]>=target)
				left=mid+1;
			else right=mid-1;
		else
			--right;//加上这一句话就OK了~~~~，叼！
	}
	return false;
}