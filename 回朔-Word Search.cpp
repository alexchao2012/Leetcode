#include"stage2.h"
/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

#define N 100

bool isSafe(int x,int y,bool used[N][N],string word,int leng,vector<vector<char> > &board){
    if(x>=0 && x<board.size() && y>=0 && y<board[0].size()  
		&& !used[x][y] && board[x][y]==word[leng])
		return true;
	return false;
}

bool dfs(int x,int y,int leng,string word,bool used[N][N],int xMove[],int yMove[],vector<vector<char> > &board){
	if(leng>=word.size())return true;

	for(int k=0;k<4;++k){
		int nextX=x+xMove[k];
		int nextY=y+yMove[k];

		if(isSafe(nextX,nextY,used,word,leng,board)){
			used[nextX][nextY]=true;
			if(dfs(nextX,nextY,leng+1,word,used,xMove,yMove,board))
				return true;
			used[nextX][nextY]=false;
		}
	}


	return false;
}			

bool exist(vector<vector<char> > &board, string word){
	if(word.empty())return true;

	bool used[N][N];
	memset(used,false,sizeof(used));

	int xMove[4]={0,1, 0,-1}; 
	int yMove[4]={1,0,-1, 0};

	for(int i=0;i<board.size();++i)
		for(int j=0;j<board[0].size();++j){
			if(word[0]==board[i][j]){
				used[i][j]=true;
				if(dfs(i,j,1,word,used,xMove,yMove,board))
					return true;
				used[i][j]=false;
			}
		}
	return false;
}

//bool dfs(vector<vector<char> > &board,string word,int leng,int X,int Y,bool **used){
//    if(leng>=word.size())return true;
//    int m=board.size(),n=board[0].size();
//	if(X>=m || Y>=n || X<0 || Y<0)return false;
//	
//	
//	if(!used[X][Y] && board[X][Y]==word[leng]){
//		used[X][Y]=true;
//		bool isOK= dfs(board,word,leng+1,X,Y+1,used) ||
//				dfs(board,word,leng+1,X+1,Y,used)||
//				dfs(board,word,leng+1,X,Y-1,used)||
//				dfs(board,word,leng+1,X-1,Y,used);
//		used[X][Y]=false;
//		return isOK;
//	}
//	return false;
//}
//
//bool exist(vector<vector<char> > &board, string word) {
//	if(board.size()==0 || board[0].size()==0 || word.size()==0)return false;
//	int m=board.size(),n=board[0].size();
//
//	bool **used=new bool*[m];
//	for(int i=0;i<m;++i){
//		used[i]=new bool[n];
//		memset(used[i],false,sizeof(bool)*n);
//	}
//
//	bool flag=false;
//	for(int i=0;i<m;++i)
//		for(int j=0;j<n;++j)
//			if(dfs(board,word,0,i,j,used)){
//				flag=true;
//				break;
//			}
//
//	for(int i=0;i<m;++i)
//		delete [] used[i];
//	delete [] used;
//
//	return flag?true:false;
//}

		