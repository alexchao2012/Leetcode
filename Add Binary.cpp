#include"stage2.h"

string addBinary(string a,string b){
    vector<char> chars;
	if(a.size()==0)return b;
	if(b.size()==0)return a;

	int lenA=a.size()-1;
	int lenB=b.size()-1;
	int carry=0;
	while(lenA>=0 || lenB>=0){
		int i1=0,i2=0,sum=0;
		if(lenA>=0)
			i1=a[lenA]-'0';
		if(lenB>=0)
			i2=b[lenB]-'0';
		sum=carry+i1+i2;
		carry=sum/2;
        sum%=2;
		chars.insert(chars.begin(),(sum+'0'));
		--lenA;
		--lenB;
	}

	stringstream oss;
	if(carry)
		oss<<(char)(carry+'0');
	for(int i=0;i<chars.size();++i)
		oss<<chars[i];
	return oss.str();
}
string addBinary2(string a, string b) {//大数的改版
	if(a.size()==0)return b;
	if(b.size()==0)return a;

	string ret;
	int carry=0;
	int len1=a.size(),len2=b.size();
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(int i=0;i<max(len1,len2);++i){
		int i1=0,i2=0,sum=0;
		if(i<len1)i1=a[i]-'0';
		if(i<len2)i2=b[i]-'0';
		sum=i1+i2+carry;
		carry=sum/2;
		ret+=(sum%2)+'0';
	}
	if(carry)
		ret+='1';
	reverse(ret.begin(),ret.end());
	return ret;
}
