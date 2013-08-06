#include<iostream>
#include<cstdio>

using namespace std;

#define N 8

static bool isSafe(int x,int y,int sol[N][N])
{
	if(x>=0 && x<N && y>=0 && y<N && sol[x][y]==-1)
		return true;
	return false;
}

void printSolution(int sol[N][N])
{
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
			printf("%d\t",sol[i][j]);
		printf("\n");
	}
}

bool solveKTUtil(int x,int y,int move,int sol[N][N],int xMove[],int yMove[])
{
	if(move==N*N)return true;

	for(int k=0;k<N;++k)
	{
		int nextX=x+xMove[k];
		int nextY=y+yMove[k];

		if(isSafe(nextX,nextY,sol))
		{
			sol[nextX][nextY]=move;

			if(solveKTUtil(nextX,nextY,move+1,sol,xMove,yMove))
				return true;
			else
				sol[nextX][nextY]=-1;
		}
	}

	return false;
}

bool solveKnightTour(int initX,int initY)
{
	int sol[N][N];

	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			sol[i][j]=-1;

	int xMove[8]={2,1,-1,-2,-2,-1, 1, 2};
	int yMove[8]={1,2, 2, 1,-1,-2,-2,-1};  

	sol[initX][initY]=0;

	if(!solveKTUtil(initX,initY,1,sol,xMove,yMove))
	{
		printf("Solution does not exist ! ");
		return false;
	}
	else
		printSolution(sol);

	return true;
}

//int main()
//{
//	int x,y;
//	while(cin>>x>>y)
//		solveKnightTour(x,y);
//
//	return 0;
//}