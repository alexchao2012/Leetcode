#include"head.h"

int climbStairs(int n){//O(n)空间复杂度O(1)但是还有logN的解法
	int f,f1=1,f2=2;
	if(n==0)
		return 0;
	if(n<=2)
		return n==1?1:2;
	int i=3;
	while(i<=n){
		f=f1+f2;
		f1=f2;
		f2=f;
		++i;
	}
	return f;
}

typedef struct matrix2by2{
	matrix2by2(
		long long m00=0,
		long long m01=0,
		long long m10=0,
		long long m11=0
		):m_00(m00),m_01(m01),m_10(m10),m_11(m11)
	{}

	long long m_00;
	long long m_01;
	long long m_10;
	long long m_11;
}m2by2;

m2by2 matrixMultiply(const m2by2 m1,const m2by2 m2)
{
	return m2by2(
		m1.m_00*m2.m_00+m1.m_01*m2.m_10,
		m1.m_00*m2.m_01+m1.m_01*m2.m_11,
		m1.m_10*m2.m_00+m1.m_11*m2.m_10,
		m1.m_10*m2.m_01+m1.m_11*m2.m_11
		);
}

m2by2 matrixPow(const int n)
{
	assert(n>0);

	m2by2 m;

	if(n==1)
		m=m2by2(1,1,1,0);

	else if(n%2==0)
	{
		m=matrixPow(n/2);
		m=matrixMultiply(m,m);
	}

	else if(n%2==1)
	{
		m=matrixPow((n-1)/2);
		m=matrixMultiply(m,m);
		m=matrixMultiply(m,m2by2(1,1,1,0));
	}

	return m;
}

/*
	| f2 f1| * | 1 1 |^n 这样可以得到最终的结果
	| f1 0 |   | 1 0 |
*/
int climbStairs1(int n){
	if(n<=2)
		return (n==1)?1:2;
	int f1=1,f2=2;
	m2by2 m=matrixPow(n-2);

	int res=m.m_00*f2+m.m_01*f1;
	return res;
}
