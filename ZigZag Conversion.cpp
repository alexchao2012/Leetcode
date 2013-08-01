#include"head.h"

string convert(string s,int nRows){

	assert(nRows>0);assert(s.length()>=0);
	if(nRows==1 || s.length()<=2)
		return s;

	vector<string> lines(nRows);
	int cnt=0;
	int len=s.length();
	int i=0;
	string res;

	while(cnt<len){
		if(i==0){
			while(i!=nRows && cnt<len){
				lines[i]+=s[cnt];
				i++;
				cnt++;
			}
		}
		else{
			i-=2;
			while(i>0 && cnt<len){
				lines[i]+=s[cnt];
				i--;
				cnt++;
			}
		}
	}
	for(i=0;i<nRows;i++)
		res+=lines[i];
	return res;
}

//string convert(string s, int row)
//{
//	string result="";
//	if(s.empty())
//		return result;
//	int len=s.length();
//	int flag=1;
//	for(int i=0;i<row;i++)
//	{
//		int k=i;
//		int count=0;
//		while(k<len){			
//			result+=s[k];
//			int temp=(count%2==0)?((row-1-i)*2):(2*i);
//			if(temp==0)
//				k+=2*row-2; 
//			else
//				k+=temp;
//			++count;
//		}
//	}
//	return result;
//}