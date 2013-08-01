#include"head.h"

int search(int A[], int n, int target){
	if(NULL==A || 0==n)
		return -1;
	int left=0,right=n-1,mid=0;
	while(left<=right){
		mid=left+((right-left)>>1);
		if(A[mid]==target)
			return mid;
		else if(A[mid]>A[right]){
			if(A[left]<=target && A[mid]>target)
				right=mid-1;
			else
				left=mid+1;
		}
		else{
			if(A[mid]<target && A[right]>=target)
				left=mid+1;
			else
				right=mid-1;
		}
	}
	return -1;
}

int binarySearch(int A[],int n,int target){
	if(NULL==A || 0==n)
		return -1;
	int left=0,right=n-1,mid=0;
	while(left<=right){
		mid=left+(right-left)>>1;
		if(A[mid]==target)
			return mid;
		if(A[mid]<target)
			left=mid+1;
		else
			right=mid-1;
	}
	
	return -1;
}
