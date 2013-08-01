#include"stage2.h"
/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
*/
void merge(int A[], int m, int B[], int n) {  
    if(A != NULL && B != NULL)  
    {  
        int pos = m + n - 1;  
        int ia = m - 1;  
        int ib = n - 1;  
        while(ia >= 0 && ib >= 0)  
        {  
            if(A[ia] > B[ib])  
                A[pos--] = A[ia--];  
            else  
                A[pos--] = B[ib--];  
        }  
        while(ib >= 0)  
            A[pos--] = B[ib--];  
    }  
}