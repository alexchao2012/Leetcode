#include"stage2.h"

typedef int elem_t;
elem_t maxsum(int n,elem_t* list){
	elem_t ret,sum=0;
	int i;
	for (ret=list[i=0];i<n;i++)
		sum=(sum>0?sum:0)+list[i],ret=(sum>ret?sum:ret);
	return ret;
}
elem_t maxsum(int n,elem_t* list,int& start,int& end){//需要再搞清，如何确定起始位置和结束位
	elem_t ret,sum=0;
	int s,i;
	for (ret=list[start=end=s=i=0];i<n;i++,s=(sum>0?s:i))
		if ((sum=(sum>0?sum:0)+list[i])>ret)
			ret=sum,start=s,end=i;
	return ret;
}

int maxSubArray2(int A[],int n){
	if(NULL==A || 0==n)
		return 0;
	int ret=A[0];
	int curMax=0;
	for(int i=0;i<n;++i){
		if(curMax>=0)
			curMax+=A[i];
		else
			curMax=A[i];
		ret=max(ret,curMax);
	}
	return ret;
}

int maxSubArray(int A[],int n){
	assert(A!=NULL && n>0);
	int sum=0,maxSum=INT_MIN;

	for(int i=0;i<n;++i){
		sum=(sum<0?0:sum)+A[i];
		maxSum=max(sum,maxSum);
	}
	return maxSum;
}
