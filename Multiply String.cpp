#include"stage2.h"

/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

string multiply(string num1, string num2){
    if(!num1.length() || !num2.length())
		return "";
	if(num1[0]=='0' || num2[0]=='0')
		return "0";
	int len1=num1.length(),len2=num2.length(),len=max(len1,len2)*2;
	vector<int> res(len+1,0),n1(len1,0),n2(len2,0);//多申请一位就是为了确保最高位进位时可以保存下来

	for(int i=len1-1,j=0;i>=0;--i,++j)
		n1[j]=num1[i]-'0';

	for(int i=len2-1,j=0;i>=0;--i,++j)
		n2[j]=num2[i]-'0';

	for(int i=0;i<len1;++i)
		for(int j=0;j<len2;++j)
			res[i+j]+=n1[i]*n2[j];

	for(int i=0;i<len;++i)
		if(res[i]>=10){
			res[i+1]+=res[i]/10;
			res[i]%=10;
		}

	string ret;
	int flag=true;
	for(int i=len;i>=0;--i){
		while(!res[i] && flag)
			--i;
		flag=false;
		ret+=res[i]+'0';

	}

	return ret;
}
