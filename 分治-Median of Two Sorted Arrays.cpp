#include"stage3.h"
/*
There are two sorted arrays A and B of size m and n 
respectively. Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).
*/
int fink(int A[], int m, int B[], int n, int k) { 
	if (m <= 0)return B[k-1]; 
	if (n <= 0)return A[k-1]; 
	
	int i = (double)m/(m+n)*k - 1;
	int j = (k-1) - i; 
	
	int Ai_1 = ((i == 0) ? INT_MIN : A[i-1]); 
	int Bj_1 = ((j == 0) ? INT_MIN : B[j-1]); 
	int Ai = ((i == m) ? INT_MAX : A[i]); 
	int Bj = ((j == n) ? INT_MAX : B[j]); 
	
	if (Bj_1 <= Ai && Ai <= Bj) return Ai;
	else if (Ai_1 <= Bj && Bj <= Ai) return Bj; 
	
	if (Ai < Bj) 
		return fink(A+i+1, m-i-1, B, j, k-i-1); 
	else
		return fink(A, i, B+j+1, n-j-1, k-j-1);
} 

double findMedianSortedArrays(int A[],int m,int B[],int n) { 
	int total = m + n;

	if (total % 2 != 0)
		return fink(A, m, B, n, total/2+1);
	else{
		double a = fink(A, m, B, n, total/2); 
		double b = fink(A, m, B, n, total/2+1);

		return (a + b)/2.0; 
	}
}

// A utility function to find median of two integers
float MO2( int a, int b ) 
{ 
	return ( a + b ) / 2.0;
}

// A utility function to find median of three integers 
float MO3( int a, int b, int c )
{ 
	return a + b + c - max( a, max( b, c ) ) - min( a, min( b, c ) ); 
}

// A utility function to find median of four integers 
float MO4( int a, int b, int c, int d ) 
{
	int Max = max( a, max( b, max( c, d ) ) );
	int Min = min( a, min( b, min( c, d ) ) );
	
	return ( a + b + c + d - Max - Min ) / 2.0;
}

float findMedianUtil( int A[], int N, int B[], int M )
{ 
	// If the smaller array has only one element 
	if( N == 1 ) 
	{ 
		// Case 1: If the larger array also has one element, simply call MO2()
		if( M == 1 ) return MO2( A[0], B[0] ); 

		//Case 2: If the larger array has odd number of elements, then consider
		// the middle 3 elements of larger array and the only element of 
		// smaller array. Take few examples like following 
		// A = {9}, B[] = {5, 8, 10, 20, 30} and 
		// A[] = {1}, B[] = {5, 8, 10, 20, 30}
		if( M & 1 ) return MO2( B[M/2], MO3(A[0], B[M/2 - 1], B[M/2 + 1]) );

		// Case 3: If the larger array has even number of element, then median 
		// will be one of the following 3 elements 
		// ... The middle two elements of larger array 
		// ... The only element of smaller array
		return MO3( B[M/2], B[M/2 - 1], A[0] ); 
	}

	// If the smaller array has two elements
	else if( N == 2 ) 
	{ 
		// Case 4: If the larger array also has two elements, simply call MO4() 
		if( M == 2 ) return MO4( A[0], A[1], B[0], B[1] );

		//Case 5: If the larger array has odd number of elements,then median
		// will be one of the following 3 elements 
		// 1. Middle element of larger array 
		// 2. Max of first element of smaller array and element just 
		// before the middle in bigger array 
		// 3. Min of second element of smaller array and element just 
		// after the middle in bigger array
		if( M & 1 ) return MO3 ( B[M/2], max( A[0], B[M/2 - 1] ), min( A[1], B[M/2 + 1] ) );

		// Case 6: If the larger array has even number of elements, then 
		// median will be one of the following 4 elements 
		// 1) & 2) The middle two elements of larger array 
		// 3) Max of first element of smaller array and element 
		// just before the first middle element in bigger array 
		// 4. Min of second element of smaller array and element 
		// just after the second middle in bigger array
		return MO4 ( B[M/2], B[M/2 - 1], max( A[0], B[M/2 - 2] ), min( A[1], B[M/2 + 1] ) ); 
	} 

	int idxA = ( N - 1 ) / 2; 
	int idxB = ( M - 1 ) / 2;

	/* if A[idxA] <= B[idxB], then median must exist in A[idxA....] and B[....idxB] */ 
	if( A[idxA] <= B[idxB] ) 
		return findMedianUtil( A + idxA, N / 2 + 1, B, M - idxA ); 

	/* if A[idxA] > B[idxB], then median must exist in A[...idxA] and B[idxB....] */
	return findMedianUtil( A, N / 2 + 1, B + idxA, M - idxA ); 
}

//if one of the two array's size is 0,then return the median of the other array!
float getMedian(int A[] ,int N){
	if(N & 1)
		return A[N/2];
	else
		return (double)(A[N/2]+A[N/2-1])/2.0;
}

// A wrapper function around findMedianUtil(). This function makes 
// sure that smaller array is passed as first argument to findMedianUtil 
float findMedian( int A[], int N, int B[], int M )//leetcode acepted !
{ 
	if (N == 0)
		return getMedian(B,M);
	if(M == 0)
		return getMedian(A,N);

	if ( N > M ) 
		return findMedianUtil( B, M, A, N ); 

	return findMedianUtil( A, N, B, M ); 
}