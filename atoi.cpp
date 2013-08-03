#include"head.h"

int atoi(const char *str){
	if(str == NULL) { return 0; }

	while(*str == ' ')
		++str;

	int sign = 1;
	if(*str == '-'){
		++str;
		sign = -1;
	}
	else if(*str == '+')
		++str;

	long long ret = 0;
	while( *str >= '0' && *str <= '9'){
		ret = ret * 10 + (*str - '0');
		if(ret > INT_MAX) { return sign < 0 ? INT_MIN : INT_MAX;}
		++str;
	}

	return int(sign*ret);
}
