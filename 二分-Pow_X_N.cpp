#include"stage2.h"

double pow0(double x, int n) { 
	double ret; 
	if (n==0) return 1; 
	int m = n>0?n:-n; 
	double v = pow0(x, m>>1); 
	ret = v*v;
	if (m&1) ret = x*ret; 
	return n<0?1/ret:ret; 
}

double pow1(double x, int n) {  
    if(0 == n)  return 1;  
    if(0 == x)  return 0;  
    int sign = 1;  
    if(n < 0){  
        sign = -1;  
        n = abs(n);  
    }  
    double temp = x;  
    double result = 1;  
    while(n > 0){  
        if(n&1 == 1)  
            result *= temp;  
        temp *= temp;  
        n >>= 1;  
    }  
    return -1 == sign? 1/result: result;  
} 



