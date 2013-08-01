#include"head.h"

int myatoi(const char *str){
	assert(str!=NULL);

	long long x=0;
	int len=strlen(str);
	int i=0;
	int sign=1;
	while(str[i]==' ')
		++i;
	if(str[i]=='+' || str[i]=='-')
		sign=(str[i++]=='+')?1:-1;
	
	while(i<len){
		if((str[i]-'0')>=0 && (str[i]-'0')<=9){
			x=x*10+(str[i]-'0');
			++i;
		}
		else
			break;
	}
	if(x*sign>=INT_MAX)
		return INT_MAX;
	else if(x*sign<=INT_MIN)
		return INT_MIN;
	else
		return (int)x*sign;
}