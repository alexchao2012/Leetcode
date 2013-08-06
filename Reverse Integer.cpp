#include"head.h"



/*32ms通过大数集合测试*/
int reverse(int x) {  
    // Start typing your C/C++ solution below  
    // DO NOT write int main() function  
    if (x < 0) return reverse(-x) * -1;  
    else if (x == 0) return 0;  
          
    int res = 0;  
          
    while (x)  
    {  
        res = res * 10 + x % 10;  
        x /= 10;  
    }  
    return res;  
}

int reverse1(int x) {
    int sup = 1;
    {//find the most significant bit
        int temp = x;
        while(temp /= 10) {
            sup *= 10;
        }
    }
    int sub = 10;
    int y = 0;//result
    while(sup >= sub) {
        int dsup = x / sup;
        int dsub = (x % sub) / (sub / 10);
        //cout<<dsup<<","<<dsub<<",";
        x -= sup * dsup;
        x -= (sub / 10) * dsub;
        //cout<<x<<"|";
        y += sup * dsub;
        y += (sub / 10) * dsup;
            
        sup /= 10;
        sub *= 10;
    }
    if (sup * 10 == sub) {
        y += x;
    }
    return y;
}

#define MAX 100
int reverse2(int x)
{
	char chars[100];
	itoa(x,chars,10);
	
	int len=0;
	int i=0;
	while(chars[i]!='\0'){
		i++;
		len++;
	}
	i=0;
	int j=len-1;
	while(i<j)
	{
		char temp=chars[i];
		chars[i]=chars[j];
		chars[j]=temp;
		i++;
		j--;
	}

	int res=atoi(chars);
	return res;
}
