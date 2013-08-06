#include"stage2.h"
/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/
void countingsort(int A[],int n,int limit){
	if(NULL==A || n<=0 )return;
	int *cnt=new int[limit+1];
	memset(cnt,0,sizeof(int)*(limit+1));

	for(int i=0;i<n;++i)
		++cnt[A[i]];
	for(int i=1;i<=limit;++i)
		cnt[i]+=cnt[i-1];

	for(int i=limit,j=n-1;i>=0;--i)
		if(i!=0)
			while(cnt[i]-cnt[i-1]){
				--cnt[i];
				A[j--]=i;
			}
		else
			while(cnt[i]){
				--cnt[i];
				A[j--]=i;
			}
}

void countingsort(int A[],int sorted[],int n,int limit){
	if(A==NULL || sorted==NULL || n<=0)return;
	int *count=new int[limit+1];
	memset(count,0,sizeof(int)*(limit+1));

	for(int i=0;i<n;++i)
		++count[A[i]];
	for(int i=1;i<=limit;++i)
		count[i]+=count[i-1];

	for(int i=n-1;i>=0;--i){
		sorted[count[A[i]]-1]=A[i];
		--count[A[i]];
	}
}
void sortColors2(int A[], int n) {
	if(A==NULL || n<=0)return;
	vector<int> cnt(3,0);

	for(int i=0;i<n;++i)
		++cnt[A[i]];
	for(int i=1;i<3;++i)
		cnt[i]+=cnt[i-1];

	for(int i=2,j=n-1;i>=0;--i)
		if(i!=0)
			while(cnt[i]-cnt[i-1]){
				A[j--]=i;
				--cnt[i];
			}
		else
			while(cnt[i]--)
				A[j--]=i;
}

void sortColor3(int A[],int n){
	if(A==NULL || n<=0)return;
	int pivot=1;
	int i=-1,j=-1,k=0;

	for(k;k<n;++k){
		if(A[k]<=pivot){
			++j;
			swap(A[j],A[k]);
		}
	}

	for(k=0;k<=j;++k){
		if(A[k]<pivot){
			++i;
			swap(A[i],A[k]);
		}
	}
}

void sortColors(int A[],int n){
    if(A==NULL || n<=0)return;
	
	int i=0,j=n-1,k=n-1;
	while(i<=j){
		if(A[i]==2){			
			swap(A[i],A[k]);
            --k;
			if(k<j)j=k;
		}
		else if(A[i]==1){			
			swap(A[i],A[j]);
            --j;
		}
		else
			++i;
	}
}