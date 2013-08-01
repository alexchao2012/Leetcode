#include"head.h"
/*
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.
Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/
int searchInsert(int A[], int n, int target){//查找大于等于target的第一个元素
	if(NULL==A || 0==n)
		return -1;
	if(target>A[n-1])
		return n;

	int left=0,right=n-1;	
	while(left<right){
		int mid=(left+right)>>1;
		if(A[mid]>=target)
			right=mid;
		else
			left=mid+1;
	}
	/*效果是一样的，这里注意判断的边界问题，是left<right。
	int left=0,right=n-1;
	int mid=(left+right)>>1;
	while(left<right){
		if(A[mid]>=target)
			right=mid;
		else
			left=mid+1;
		mid=(left+right)>>1;
	}
	return mid;
	*/
	return left;
}

int searchInsert2(int A[], int n, int target){//查找大于等于target的第一个元素
    if(A==NULL || n<0) return -1;
    
    if(target>A[n-1]) return n;
    
    int left=0,right=n-1,mid=(left+right)>>1;
    
    while(left<right){
        if(A[mid]<target)
            left=mid+1;
        else
            right=mid;
        
        mid=(left+right)>>1;
    }
    
    return mid;
}