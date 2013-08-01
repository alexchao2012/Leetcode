#include"stage2.h"

bool canJump(int A[], int n) {//每次保留最远跳，最后可以得到最大值  
    if(NULL == A || 0 == n)  
        return true;  
    int rightmost = 0;  
    for(int i = 0; i < n; ++i)  
    {  
        if(i <= rightmost)  
            rightmost = max(rightmost, i + A[i]);  
    }  
    return rightmost >= n - 1;  
} 

bool canJump2(int A[], int n) {//贪心
    if(NULL==A || 0==n)
		return false;
	if(n==1)return true;
	int span=0,cnt=0;
	while(span<n-1){
		if(A[span]==0)
			return false;
		if(span+A[span]>=n)
			return true;
		span+=A[span];
		cnt++;
	}
    return true;
}
		