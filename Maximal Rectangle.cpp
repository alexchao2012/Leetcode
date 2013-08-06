#include"stage2.h"
/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/

int largestRectangleArea4(vector<int> &height) {  //µ¥µ÷Õ»
    // Start typing your C/C++ solution below  
    // DO NOT write int main() function  
    int q[100000] = {-1};  
    int w[100000];  
          
    int res = 0;  
    int top = 0;  
    for (int i = 0; i <= height.size(); ++i)  
    {  
        int h;  
        i == height.size() ? h = 0: h = height[i];  
              
        if (h > q[top])  
        {  
            q[++top] = h;  
            w[top] = 1;  
        }  
        else  
        {  
            int cnt = 0;  
            while (h <= q[top])  
            {  
                res = max(res, (w[top] + cnt) * q[top]);  
                cnt += w[top--];  
            }  
            q[++top] = h;  
            w[top] = cnt + 1;  
        }  
    }  
    return res;  
}
 int maximalRectangle(vector<vector<char> > &matrix) {
	 if(matrix.size()==0 || matrix[0].size()==0)return 0;
	 int m=matrix.size(),n=matrix[0].size(),ret=INT_MIN;
	 vector<vector<int> > M(m,vector<int>(n));

	 for(int i=0;i<m;++i)
		 for(int j=0;j<n;++j)
			 M[i][j]=matrix[i][j]=='0'?0:1;

	 for(int i=1;i<m;++i)
		for(int j=0;j<n;++j)
			M[i][j]+=M[i][j]==0?0:M[i-1][j];

	 for(int i=0;i<m;++i){
		 int curMax=largestRectangleArea4(M[i]);
		 if(curMax>ret)ret=curMax;
	 }

	 return ret;
 }
