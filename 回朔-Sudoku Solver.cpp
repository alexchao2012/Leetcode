#include"stage3.h"
/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/

const int N=9;

bool usedInRow(int grid[N][N],int row,int num)
{
	for(int col=0;col<N;++col)
		if(grid[row][col]==num)
			return true;
	return false;
}

bool usedInCol(int grid[N][N],int col,int num)
{
	for(int row=0;row<N;++row)
		if(grid[row][col]==num)
			return true;
	return false;
}

bool usedInBox(int grid[N][N],int startRow,int startCol,int num)
{
	for(int row=0;row<3;++row)
		for(int col=0;col<3;++col)
			if(grid[startRow + row][startCol + col]==num)
				return true;
	return false;
}

bool isSafe(int grid[N][N],int row,int col,int num)
{
	return !usedInRow(grid,row,num) &&
			!usedInCol(grid,col,num) && 
			!usedInBox(grid,row-row%3,col-col%3,num);
}


bool findUnassinged(int grid[N][N],int &row,int &col)
{
	for(row=0;row<N;++row)
		for(col=0;col<N;++col)
			if(grid[row][col]==0)
				return true;
	return false;
}

bool solveSudoku(int grid[N][N])
{
	int row,col;

	if(!findUnassinged(grid,row,col))
		return true;

	for(int num=1;num<=9;++num)
	{
		if(isSafe(grid,row,col,num))
		{
			grid[row][col]=num;

			if(solveSudoku(grid))
				return true;

			grid[row][col]=0;
		}
	}

	return false;
}

static void printGrid(int grid[N][N]) 
{ 
	for (int row = 0; row < N; row++) 
	{ 
		for (int col = 0; col < N; col++) {
			if(col%3 == 0 && col!=0)printf("\t");
			printf("%4d", grid[row][col]); 
		}
		if((row+1)%3 == 0 && row!=0)
			printf("\n");
		printf("\n"); 
	} 
}

//int main(){
//	int grid[N][N] = 
//	{
//		{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
//		{5, 2, 0, 0, 0, 0, 0, 0, 0}, 
//		{0, 8, 7, 0, 0, 0, 0, 3, 1}, 
//		{0, 0, 3, 0, 1, 0, 0, 8, 0}, 
//		{9, 0, 0, 8, 6, 3, 0, 0, 5}, 
//		{0, 5, 0, 0, 9, 0, 6, 0, 0}, 
//		{1, 3, 0, 0, 0, 0, 2, 5, 0}, 
//		{0, 0, 0, 0, 0, 0, 0, 7, 4}, 
//		{0, 0, 5, 2, 0, 6, 3, 0, 0}
//	};
//
//	if (solveSudoku(grid) == true) 
//		printGrid(grid); 
//	else 
//		printf("No solution exists"); 
//	return 0;
//}

//void solveSudoku(vector<vector<char> > &board) {//添加进leetcode中的时候使用的变换函数
//    int grid[N][N];
//    for(int i=0;i<9;++i)
//        for(int j=0;j<9;++j)
//            if(board[i][j]=='.')
//                grid[i][j]=0;
//            else
//                grid[i][j]=board[i][j]-'0';
//    solve(grid);
//        
//    for(int i=0;i<9;++i)
//        for(int j=0;j<9;++j)
//            board[i][j]=grid[i][j]+'0';
//        
//}

/*
    vector<vector<bool> > rows;
    vector<vector<bool> > cols;
    vector<vector<bool> > blocks;

    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        rows.clear();
        cols.clear();
        blocks.clear();
        rows.resize(9, vector<bool>(9, false));
        cols.resize(9, vector<bool>(9, false));
        blocks.resize(9, vector<bool>(9, false));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c != '.') {
                    rows[i][c - '1'] = cols[j][c - '1'] = blocks[(i / 3) * 3 + j / 3][c - '1'] = true;
                }
            }
        }

        sub(board, 0);
    }

    bool sub(vector<vector<char> > &board, int index) {

        while (index < 81 && board[index / 9][index % 9] != '.')
            index++;

        if (index == 81) return true;

        int row = index / 9, col = index % 9;
        for (int i = 0; i < 9; ++i) {
            if (rows[row][i] || cols[col][i] || blocks[(row / 3) * 3 + col / 3][i]) continue;
            rows[row][i] = cols[col][i] = blocks[(row / 3) * 3 + col / 3][i] = true;
            board[row][col] = '1' + i;
            if (sub(board, index + 1))
                return true;
            board[row][col] = '.';
            rows[row][i] = cols[col][i] = blocks[(row / 3) * 3 + col / 3][i] = false;
        }

        return false;
    }
*/