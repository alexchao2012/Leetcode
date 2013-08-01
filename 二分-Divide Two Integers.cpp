#include<iostream>
#include<cassert>

using namespace std;
/*
Divide two integers without using multiplication, 
division and mod operator.
*/

int divide(int dividend, int divisor)   
{    
	long long x=dividend;//这里如果不适用long long 则会超时？这是为什么呢？
	long long y=divisor;//如果是负的最大值，转化为正数，则越界，故用long long
						//（如果是long，因为多数int和long一样，则同样不行）
	assert(y!=0);
	bool isNegtive=(x^y)<0;//判断异号
	if(x<0)x=-x;
	if(y<0)y=-y;

	int bound=0;
	while((y<<bound)<=x)
		++bound;
	--bound;//统计x最多可以减掉多少次幂的y

    int ans=0;
    for(int i=bound;i>=0;--i)  
    {    
    //比较x是否大于y的(1<<i)次方，避免将x与(y<<i)比较，因为不确定y的(1<<i)次方是否溢出  
        if((x>>i)>=y)           
        {       
            ans+=(1<<i);      
            x-=(y<<i);        
        }       
    }    
    return isNegtive?-ans:ans;    
}    
//
//int main(){
//	int m,n;
//	while(cin>>m>>n)
//		cout<<divide1(m,n)<<endl;
//
//	return 0;
//}