#include"stage2.h"
/*
DP  需要再看，未解决
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

int jump(int A[], int n)  
{  
    if(NULL == A || n <= 1)  
        return 0;  
          
    int steps = 0;  
    int idx = 0;  
    while(idx < n)  
    {  
        if(A[idx] > 0)  
            ++steps;  
        else  
            return 0;  
        int rightmost = A[idx] + idx;  
        if(rightmost >= n - 1)  
            return steps;  
        int temp = 0;  
        for(int j = idx + 1; j <= rightmost; ++j)  
            if(A[j] + j >= temp)  
            {  
                temp = A[j] + j;  
                idx = j;  
            }  
    }  
    return steps;  
} 

int jump2(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int minstep = 0;
    int ldist = 0;
    int hdist = 0;
    if (n == 1) return 0;
    while(ldist <= hdist) {
        ++minstep;
        int lasthdist = hdist;
        for(int i = ldist; i <= lasthdist; ++i) {
            int possibledist = i + A[i];
            if (possibledist >= n-1)
                return minstep;
            if (possibledist > hdist) {
                hdist = possibledist;
            }
        }
        ldist = lasthdist + 1;
    }
    return 0;
}
//int jump(int A[], int n) {//错误！
//	if(0==n || NULL==A)
//		return 0;
//	if(n==1)return 0;
//
//	int *dp=new int[n];
//	for(int i=n-2;i>=0;++i){
//		if(A[i]+i>=n-1)
//			dp[i]=1;
//		else
//			dp[i]=min(1+dp[A[i]+i],dp[i+1]);
//	}
//	return dp[0];
//}
