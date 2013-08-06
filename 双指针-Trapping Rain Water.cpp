#include"stage2.h"

int trap(int A[], int n) { 
	if (!A || !n) return 0; 
	
	int mid = 0, water = 0, h = 0; 
	
	for (int i = 0; i < n; ++i)
		if (A[i] > A[mid]) mid = i;
	
	for (int i = 0; i < mid; ++i) 
		if (h > A[i]) 
			water += h - A[i];
		else 
			h = A[i]; 
		
	h = 0; 
	for (int i = n - 1; i > mid; --i) 
		if (h > A[i])
			water += h - A[i]; 
		else
			h = A[i];
		
	return water;
}

int trap1(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
	if(!A || !n) return 0;

    int *leftMaxHeight = new int[n];
    int *rightMaxHeight = new int[n];

    for(int i=0; i<n; i++) {
        if(i==0) {
            leftMaxHeight[i] = 0;
            rightMaxHeight[n-1] = 0;
        }
        else {
            leftMaxHeight[i] = max(leftMaxHeight[i-1], A[i-1]);
            rightMaxHeight[n-1-i] = max(rightMaxHeight[n-i], A[n-i]); 
        }
    }

    int sum = 0;
    for(int i=0; i<n; i++) {

        int height = min(leftMaxHeight[i], rightMaxHeight[i]);
        if (height > A[i]) {
            sum += height-A[i];
        }
    }

    delete [] leftMaxHeight;
	delete [] rightMaxHeight;

    return sum;
}