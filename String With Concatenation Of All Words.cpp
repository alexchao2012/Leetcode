#include"head.h"

vector<int> findSubstring(string S, vector<string> &L){
	

	map<string,int> table,curStr;
	for(int i=0;i<L.size();++i)
		++table[L[i]];

	vector<int> ret;
	int N=L.size();
	if(N<=0)
		return ret;

	int M=L[0].size();
	for(int i=0;i<=(int)S.size()-N*M;++i){
		curStr.clear();
		int j=0;
		for(j=0;j<N;++j){
			string temp=S.substr(i+j*M,M);
			if(table.find(temp)==table.end())
				break;
			++curStr[temp];
			if(curStr[temp]>table[temp])
				break;
		}
		if(j==N)ret.push_back(i);
	}
	return ret;
}
    vector<int> findSubstring1(string S, vector<string> &L) {  
        map<string, int> words;  
        map<string, int> curStr;  
        for(int i = 0; i < L.size(); ++i)  
            ++words[L.at(i)];  
        int N = L.size();  
        vector<int> ret;  
        if(N <= 0)   return ret;  
        int M = L.at(0).size();  
        for(int i = 0; i <= (int)S.size()-N*M; ++i)  
        {  
            curStr.clear();  
            int j = 0;  
            for(j = 0; j < N; ++j)  
            {  
                string w = S.substr(i+j*M, M);  
                if(words.find(w) == words.end())  
                    break;  
                ++curStr[w];  
                if(curStr[w] > words[w])  
                    break;  
            }  
            if(j == N)  ret.push_back(i);  
        }  
        return ret;  
    }  