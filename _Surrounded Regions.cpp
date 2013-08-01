#include"stage3.h"
/*
Given a 2D board containing 'X' and 'O', capture all 
regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in
that surrounded region .

For example,

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/
vector<pair<int,int>> BFS(int curX, int curY, vector<vector<char>> &board, vector<vector<bool>>& visited, bool& bFilp)  
{  
    int n = board.size();  
    int m = board[0].size();  
    int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};  
    queue<pair<int, int>> q;  
    visited[curX][curY] = true;  
    q.push(make_pair(curX, curY));  
    vector<pair<int,int>> path;  
    while (!q.empty())  
    {  
        int x = q.front().first;   
        int y = q.front().second;  
        path.push_back(q.front());  
        q.pop();  
        for (int i = 0; i < 4; ++i)  
        {  
            int nextX = x+dir[i][0];  
            int nextY = y+dir[i][1];  
            if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m)  
            {  
                if(!visited[nextX][nextY] && board[nextX][nextY] == 'O')  
                {  
                    q.push(make_pair(nextX, nextY));  
                    visited[nextX][nextY] = true;  
                }  
                      
            }  
            else bFilp = false;  
                  
        }  
    }  
    return path;  
}  

void solve(vector<vector<char>> &board) {  
    // Start typing your C/C++ solution below  
    // DO NOT write int main() function  
    int n = board.size();  
    if(n == 0) return;  
    int m = board[0].size();  
    vector<vector<bool>> visited;  
    visited.resize(n);  
    for(int i = 0; i < n; ++i)  
        visited[i].assign(m, false);  
    for (int i = 0; i < n; ++i)  
    {  
        for (int j = 0; j < m; ++j)  
        {  
            if(!visited[i][j] && board[i][j] == 'O')  
            {  
                bool bFlip = true;  
                vector<pair<int,int>> path = BFS(i, j, board, visited, bFlip);  
                if(bFlip)  
                {  
                    for (int pIdx = 0; pIdx < path.size(); ++pIdx)  
                        board[path[pIdx].first][path[pIdx].second] = 'X';  
                }  
            }  
        }  
    }  
}