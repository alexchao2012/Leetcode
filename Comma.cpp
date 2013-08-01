#include"head.h"

void eraseComma(char *a){
	if(a==NULL)
		return;
	int i,cnt=0;
	int len=strlen(a);
	for(i=0;i<len;i++){
		if(a[i]==','){
			++cnt;
			continue;
		}
		a[i-cnt]=a[i];
	}
	a[i-cnt]='\0';
}

void eraseComma2(char *a){
	int length=strlen(a);
	int j = 0;
	for (int i = 0; i < length; i++) {
		if (a[i] != ',') {
			a[j++] = a[i];
		}
	}
}