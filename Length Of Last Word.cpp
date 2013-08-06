#include"stage2.h"

int lengthOfLastWord(const char *s) {
	if(strlen(s)==0)return 0;
	int len=strlen(s);
	int i=len-1;

	while(i>=0 && s[i]==' ')
		--i;
	if(i<0)return 0;

	int cnt=0;
	while(i>=0 && s[i]!=' '){
		--i;
		++cnt;
	}

	return cnt;
}
