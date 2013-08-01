#include"stage2.h"
/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/
void rotate2(vector<vector<int> > &matrix) {//这里极其容易写错的一点是：matrix[offset][i+offset],这样做就成了180°旋转了
	if(matrix[0].size()<=1)
		return;
	int n=matrix[0].size();
	int layer=n>>1;
	for(int offset=0;offset<layer;++offset)
		for(int i=offset;i<n-offset-1;++i){
			int temp=matrix[offset][i];
			matrix[offset][i]=matrix[n-i-1][offset];
			matrix[n-i-1][offset]=matrix[n-offset-1][n-i-1];
			matrix[n-offset-1][n-i-1]=matrix[i][n-offset-1];
			matrix[i][n-offset-1]=temp;
		}
}

    void rotate(vector<vector<int> > &matrix) { //巧 
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        int n = matrix.size();  
          
        for (int i = 0; i < n / 2; ++i)  
        {  
            for (int j = 0; j < n; ++j)  
                swap(matrix[i][j], matrix[n - i - 1][j]);  
        }  
          
        for (int j = 0; j < n; ++j)  
        {  
            for (int i = 0; i < j; ++i)  
                swap(matrix[i][j], matrix[j][i]);  
        }  
    }  
      
    void swap(int& a, int& b)  
    {  
        if (a == b)  
            return;  
              
        a = a ^ b;  
        b = a ^ b;  
        a = a ^ b;  
    } 