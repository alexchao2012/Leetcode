#include<iostream>
#include<cassert>

using namespace std;
/*
Divide two integers without using multiplication, 
division and mod operator.
*/

int divide(int dividend, int divisor)   
{    
	long long x=dividend;//�������������long long ��ᳬʱ������Ϊʲô�أ�
	long long y=divisor;//����Ǹ������ֵ��ת��Ϊ��������Խ�磬����long long
						//�������long����Ϊ����int��longһ������ͬ�����У�
	assert(y!=0);
	bool isNegtive=(x^y)<0;//�ж����
	if(x<0)x=-x;
	if(y<0)y=-y;

	int bound=0;
	while((y<<bound)<=x)
		++bound;
	--bound;//ͳ��x�����Լ������ٴ��ݵ�y

    int ans=0;
    for(int i=bound;i>=0;--i)  
    {    
    //�Ƚ�x�Ƿ����y��(1<<i)�η������⽫x��(y<<i)�Ƚϣ���Ϊ��ȷ��y��(1<<i)�η��Ƿ����  
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