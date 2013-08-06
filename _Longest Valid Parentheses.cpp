#include"head.h"
/*
	Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/
int longestValidParentheses1(string s){
	stack<int> st;
	int ret=0;
	int legalTop=s.size();
	for(int i=0;i<s.size();++i){
		if(s[i]=='(')
			st.push(i);
		else if(st.empty())
			legalTop=i+1;
		else{
			legalTop=min(legalTop,st.top());
			st.pop();
			if(st.empty())
				ret=max(ret,i-legalTop+1);
			else
				ret=max(ret,i-st.top());
		}
	}
	return ret;
}

struct node  
{  
    char c;  
    int idx;  
    node() {}  
    node(char _c, int _idx): c(_c), idx(_idx) {}          
};  
      
int longestValidParentheses2(string s) {  
    // Start typing your C/C++ solution below  
    // DO NOT write int main() function  
    stack<node> st;  
    st.push(node(')', -1));  
    int res = 0;  
          
    for (int i = 0; i < s.size(); ++i)  
    {  
        char c = s[i];  
        if (c == '(')  
            st.push(node(c, i));  
        else  
        {  
            node top = st.top();  
            if (top.c == '(')  
            {  
                st.pop();  
                res = max(res, i - st.top().idx);  
            }  
            else  
                st.push(node(c, i));  
        }  
    }  
          
    return res;  
} 


int longestValidParentheses(string s){//思路有问题，错！
	if(s.length()<=1)return 0;
	int len=s.length();
	int **dp=new int*[len];
	for(int i=0;i<len;++i)
		dp[i]=new int[len];
	for(int i=0;i<len;++i)
		dp[i][i]=0;	
	for(int i=0;i<len;++i)
		dp[i][i-1]=0;
	for(int l=2;l<=len;++l)
		for(int i=0;i<len-l+1;++i){
			int j=i+l-1;
			if(s[i]=='(' && s[j]==')')
				dp[i][j]=dp[i+1][j-1];
			
			else
				dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
		}
	int min=dp[0][len-1];
	for(int i=0;i<len;++i)
		delete [] dp[i];
	delete [] dp;
	return min;
}