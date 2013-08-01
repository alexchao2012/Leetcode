#include"stage3.h"

bool isSafe(int v,int c,vector<int> &color,vector<vector<int> > &graph){
	for(int i=0;i<graph.size();++i)
		if(graph[v][i] && color[i]==c)
			return false;
	return true;
}

void dfs(int v,int total,vector<int> &color,vector<vector<int> > &graph,vector<vector<int> > &ret){
	if(v==graph.size()){
			ret.push_back(color);
		return;
	}

	for(int c=1;c<=total;++c){
		if(isSafe(v,c,color,graph)){
			color[v]=c;
			dfs(v+1,total,color,graph,ret);
			color[v]=0;
		}
	}
}

vector<vector<int> > graphColoring(vector<vector<int> > graph,int total){
	vector<vector<int> > ret;
	if(graph.size()==0 || graph[0].size()==0 || total<=0) return ret;

	int n=graph.size();
	vector<int> color(n,0);
	ret.resize(n,vector<int>(n,0));

	dfs(0,total,color,graph,ret);

	return ret;
}

//int main(){
//	vector<vector<int> > graph(4,vector<int>(4,0));
//	int g[4][4] = {{0, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 0}};
//	for(int i=0;i<4;++i)
//		for(int j=0;j<4;++j)
//			graph[i][j]=g[i][j];
//
//	vector<vector<int> > ret=graphColoring(graph,3);
//
//	for(int i=0;i<ret.size();++i){
//		for(int j=0;j<ret[0].size();++j)
//			cout<<ret[i][j]<<'\t';
//		cout<<endl;
//	}
//
//	return 0;
//}
