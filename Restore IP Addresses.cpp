#include"stage2.h"
/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

int getIP(string s){
    int sum=0;
	for(int i=0;i<s.size();++i)
		sum=10*sum+(s[i]-'0');
	return sum;
}

void dfs(string s,int pos,int segment,vector<string> &path,vector<string> &ret){
	if(segment>4 || pos>s.size())return;
	if(segment<4 && pos>=s.size())return;
	if(segment==4 && pos==s.size()){
		string ip;
		for(int i=0;i<3;++i){
			ip+=path[i];
			ip+='.';
		}
		ip.append(path.back());
		ret.push_back(ip);
		return;
	}
	for(int l=1;l<=3;++l){
		string temp=s.substr(pos,l);
		if(getIP(temp)>255)continue;

		path.push_back(temp);
		dfs(s,pos+l,segment+1,path,ret);
		path.pop_back();
        if(getIP(temp)==0)break;
	}
}

vector<string> restoreIpAddresses(string s) {
	vector<string> ret;
	if(s.size()<4 || s.size()>12)return ret;

	vector<string> path;
	dfs(s,0,0,path,ret);
	return ret;
}

void partitionIP(string s, int startIndex, int partNum, string resultIp, vector<string>& col){ 
	if(s.size() - startIndex > (4-partNum)*3) return; 
	if(s.size() - startIndex < (4-partNum)) return; 
	if(startIndex == s.size() && partNum ==4){ 
		resultIp.resize(resultIp.size()-1); 
		col.push_back(resultIp); 
		return; 
	}
	int num =0; 
	for(int i = startIndex; i< startIndex +3; i++){ 
		num = num*10 + (s[i]-'0'); 
		if(num<=255){ 
			resultIp+=s[i]; 
			partitionIP(s, i+1, partNum+1, resultIp+'.', col); 
		} 
		if(num ==0)
			break; 
	} 
}
vector<string> restoreIpAddresses2(string s) { 
	vector<string> col; 
	string ip;
	partitionIP(s, 0, 0, ip, col); 
	return col;
}

