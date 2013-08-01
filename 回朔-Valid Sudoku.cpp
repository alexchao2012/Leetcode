#include"head.h"
/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.
*/
bool isValidSudoku(vector<vector<char> > &board){
	set<char> nums;
	
	for(int i=0;i<9;++i){
		nums.clear();
		for(int j=0;j<9;++j){
			if(board[i][j]=='.')
				continue;
			if(nums.count(board[i][j]))
				return false;
			else
				nums.insert(board[i][j]);
		}		
	}

	for(int i=0;i<9;++i){
		nums.clear();
		for(int j=0;j<9;++j){
			if(board[j][i]=='.')
				continue;
			if(nums.count(board[j][i]))
				return false;
			else
				nums.insert(board[j][i]);
		}		
	}

	for(int x=0;x<9;x+=3)
		for(int y=0;y<9;y+=3){
			nums.clear();
			for(int i=0;i<3;++i)
				for(int j=0;j<3;++j){
					if(board[i+x][j+y]=='.')
						continue;
					if(nums.count(board[i+x][j+y]))
						return false;
					else
						nums.insert(board[i+x][j+y]);
				}						
		}
	return true;
}

bool isValidSudoku2(vector<vector<char> > &board) {//极其巧妙的方法，慢慢消化
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<bool> > rows(9, vector<bool>(9, false));
    vector<vector<bool> > cols(9, vector<bool>(9, false));
    vector<vector<bool> > blocks(9, vector<bool>(9, false));

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') continue;
            int c = board[i][j] - '1';
            if (rows[i][c] || cols[j][c] || blocks[i - i % 3 + j / 3][c])
                return false;
            rows[i][c] = cols[j][c] = blocks[i - i % 3 + j / 3][c] = true;
        }
    }
    return true;
}