#include"head.h"

string intToRoman(int num){
	string symbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
	int value[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
	int i=0;
	string res;
	while(num!=0){
		if(num>=value[i]){
			num-=value[i];
			res+=symbol[i];
		}
		else
			++i;
	}

	return res;
}

int c2n(char c)
{
	switch(c){
	case 'M':return 1000;
	case 'D':return 500;
	case 'C':return 100;
	case 'L':return 50;
	case 'X':return 10;
	case 'V':return 5;
	case 'I':return 1;
	default:return 0;
	}
}

int romanToInt(string s){
	if(s.size()<1)
		return 0;
	int res=0;
	int len=s.length();

	int i=1;
	while((i-1)<len){
		if(c2n(s[i-1])>=c2n(s[i])){
			res+=c2n(s[i-1]);
			i++;
		}
		else{
			res+=c2n(s[i])-c2n(s[i-1]);
			i+=2;
		}
	}
	return res;
}


	