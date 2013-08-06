#include"stage3.h"
/*
Given a string s, partition s such that every substring of the partition 
is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
int minCut(string s) {  
    // Start typing your C/C++ solution below  
    // DO NOT write int main() function  
    int len = s.size();  
    vector<int> dp(len+1);//dp[i]: minimum cut between [i,len-1]  
    for(int i = 0; i <= len; ++i)  
        dp[i] = len-i;  
    vector<vector<bool>> p;//p[i][j]: sub string [i,j] palindrome?   
    p.resize(len);  
    for(int i = 0; i < len; ++i)  
        p[i].assign(len, false);  
    for (int i = len-1; i >= 0; --i)  
    {  
        for (int j = i; j < len; ++j)  
        {  
            if(s[i] == s[j] && (j-i < 2 || p[i+1][j-1]))  
            {  
                p[i][j] = true;  
                dp[i] = min(dp[i], 1+dp[j+1]);  
            }  
        }  
    }  
    return dp[0]-1;  
}
	