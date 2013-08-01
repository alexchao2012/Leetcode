#include"head.h"
/*
Implement strStr().
Returns a pointer to the first occurrence of needle in haystack, 
or null if needle is not part of haystack.
*/

/*KMP method time:O(n) preprocesses:O(m)*/

void computeLPS(char *pat,int *lps){
	int len=0;
	int i=1,M=strlen(pat);
	lps[0]=0;
	while(i<M)
		if(pat[i]==pat[len]){
			++len;
			lps[i]=len;
			++i;
		}
		else
			if(len!=0)
				len=lps[len-1];
			else{
				lps[i]=0;
				++i;
			}
}

vector<int> KMPSearch(char *pat,char *txt){
	vector<int> ret;
	if(!*pat || !*txt)return ret;

	int M=strlen(pat),N=strlen(txt);
	int *lps=new int[M];
	computeLPS(pat,lps);

	int i=0,j=0;
	while(i<N){
		if(txt[i]==pat[j]){
			++i;
			++j;
		}
		if(j==M){
			ret.push_back(i-j);
			j=lps[j-1];
		}
		else if(txt[i]!=pat[j]){
			if(j!=0)
				j=lps[j-1];
			else
				i+=1;
		}
	}

	delete [] lps;

	return ret;
}

vector<int> computePrefix(string s){
	int len=s.length();
	vector<int> res(len);
	if(len==0) 
		return res;
	res[0]=-1;
	int k=-1;
	for(int q=1;q<len;++q){
		while(k>=0 && s[k+1]!=s[q])
			k=res[k];
		if(s[k+1]==s[q])
			++k;
		res[q]=k;
	}
	return res;
}

vector<int> kmpStrMatch(string str,string target){
	vector<int>res;
	if(str.empty() || target.empty())
		return res;
	int sLen=str.length();
	int tLen=target.length();
	vector<int> prefix=computePrefix(target);

	int q=-1;
	for(int i=0;i<sLen;++i){
		while(q>=0 && target[q+1]!=str[i])
			q=prefix[q];
		if(target[q+1]==str[i])
			++q;
		if(q==tLen-1){
			res.push_back(i-tLen+1);
			q=prefix[q];
		}
	}
	return res;
}

char *strStr5(char *haystack, char *needle){
	int tLen=strlen(haystack);
	int pLen=strlen(needle);
	if(!pLen)
		return haystack;
	if(!tLen)
		return NULL;

	for(int i=0;i<=tLen-pLen;++i){
		int len=i;
		int j=0;
		while(haystack[len]==needle[j] && haystack[len]!='\0' && needle[j]!='\0'){
			++len;
			++j;
		}
		if(j==pLen)
			return &haystack[i];
	}
	return NULL;
}

char *strStr4(char *haystack, char *needle){
    if(!strlen(needle))
		return haystack;
	if(!strlen(haystack))
		return NULL;
	int tLen=strlen(haystack);
	int pLen=strlen(needle);

	char *p=haystack;
	char *q=needle;
	while(p!=(haystack+tLen-pLen+1)){
		char *temp=p;
		while(*temp==*q && q!=needle+pLen ){
			++temp;
			++q;
		}
		if(q==needle+pLen)
			return p;
		else
			q=needle;
		++p;
	}
	return NULL;
}

char* StrStr3(char *str, const char *target) {
  if (!*target) return str;
  char *p1 = (char*)str, *p2 = (char*)target;
  char *p1Adv = (char*)str;
  while (*++p2)
    p1Adv++;
  while (*p1Adv) {//巧，控制运行次数
    char *p1Begin = p1;
    p2 = (char*)target;
    while (*p1 && *p2 && *p1 == *p2) {
      p1++;
      p2++;
    }
    if (!*p2)
      return p1Begin;
    p1 = p1Begin + 1;
    p1Adv++;
  }
  return NULL;
}