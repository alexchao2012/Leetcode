#include"head.h"
/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

#include"head.h"

vector<int> searchRange(int A[],int n,int target){
	vector<int> ret(2,-1);
	if(A==NULL || n<=0)
		return ret;
	
	int left=0;
	int right=n-1;

	while(left<=right){
		int mid=left+((right-left)>>1);
		if(A[mid]>target)
			right=mid-1;
		else if(A[mid]<target)
			left=mid+1;
		else{
			int pivot=mid;
			while(pivot>=0 && A[pivot]==target)
				--pivot;
			ret[0]=pivot+1;
			
			pivot=mid;
			while(pivot<n && A[pivot]==target)
				++pivot;
			ret[1]=pivot-1;
			
			return ret;
		}
	}
	return ret;
}

int BSUpperBound1(int A[],int n,int target){//�ϸ��Ͻ�
	if(NULL==A || 0==n)
		return -1;
	if(A[n-1]<=target)
		return -1;

	int left=0,right=n-1;
	int mid=left+((right-left)>>1);
	while(left<right){		
		if(A[mid]>target)
			right=mid;
		else
			left=mid+1;
		mid=left+((right-left)>>1);
	}
	return mid;
}
int BSLowerBound1(int A[],int n,int target){//�ϸ��½�
	if(NULL==A || 0==n)
		return -1;
	if(A[0]>=target)
		return -1;
	int left=0,right=n-1;
	int mid=(left+right+1)>>1;//����һ��Ҫע��
							   /*�½�Ѱ�һ������Ͻ���ͬ����Ҫע�������ȡ�м�����
							   ʱ��ʹ��������ȡ������֮ͬǰһ��ʹ������ȡ������
							   ô��low == high-1����array[low] ��С�� targetʱ
							   �ͻ��γ���ѭ������Ϊlow�޷�����������high��*/
	while(left<right){
		if(A[mid]<target)
			left=mid;
		else
			right=mid-1;
		mid=(left+right+1)>>1;
	}
	return mid;
}
vector<int> searchRange3(int A[],int n,int target){
	vector<int> ret(2,-1);
	if(NULL==A || 0==n)
		return ret;
	int lower=BSLowerBound1(A,n,target);
	lower+=1;
	if(A[lower]==target)
		ret[0]=lower;
	else
		return ret;

	int upper=BSUpperBound1(A,n,target);
	upper=upper<0?(n-1):(upper-1);
	ret[1]=upper;
	return ret;
}



