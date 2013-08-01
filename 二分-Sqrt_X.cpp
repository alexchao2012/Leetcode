#include"stage2.h"
/*
ţ�ٹ�ʽ��t1=((t0 +(x/t0))/2.
���ȣ�x=x0-f(x0)/f'(x0);
��Σ�t^2-x=0��������t��t��ƽ��Ϊx
*/

double mySqrt(int x){
	if(x<=1)return x;
	double ret=x;
	double precision=1e-5;
	while(abs(ret*ret-x)>precision){
		ret=(ret+x/ret)/2;
	}
	return ret;
}
 int sqrt2(int x) {
	 if(x<=1)return x;
	 double tpre=x;
	 double t=x;

	 for(int i=0;i<20;++i){
		 t=(tpre+(x/tpre))/2;
		 tpre=t;
	 }

	 return floor(t);
 }

 int sqrt3(int x) { //���ַ��ƽ�
	 long long left = 0; 
	 long long right = x; 
	 long long xx = x; 
	 while(left <= right){ 
		 long long m = (right+left)/2; 
		 if(m*m<=xx && (m+1)*(m+1)>xx) 
			 return (int) m; 
		 if(m*m < xx) left = m+1; 
		 else if(m*m > xx) 
			 right = m-1; 
	 } 
	//��Ӧ�ü�һ��ʲôreturn�ã�
 }