#include"head.h"

void print(vector<char> path){
	for(int i=0;i<path.size()-1;++i)
		printf("%c\t",path[i]);
	printf("%c\n",path[path.size()-1]);
}

void dfs(int curLeng,int leng,char *phone,vector<char> path, char tab[][5]){
	if(curLeng>leng)
		return;
	if(curLeng==leng){
		print(path);
		return;
	}

	int number=phone[curLeng]-'0';

	for(int i=0;tab[number][i]!='\0';++i){
		path.push_back(tab[number][i]);
		dfs(curLeng+1,leng,phone,path,tab);
		path.pop_back();
	}
}

void phone2Words(char *phone){//验证通过
	if(strlen(phone)==0)
		return;

	int leng=strlen(phone);

	char tab[10][5]={
		{'0','\0'},
		{'1','\0'},
		{'A','B','C','\0'},
		{'D','E','F','\0'},
		{'G','H','I','\0'},
		{'J','K','L','\0'},
		{'M','N','O','\0'},
		{'P','Q','R','S','\0'},
		{'T','U','V','\0'},
		{'W','X','Y','Z','\0'}
	};

	vector<char> path;
	dfs(0,leng,phone,path,tab);
}


