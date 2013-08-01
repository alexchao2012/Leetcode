#include"head.h"
/*
	生成合法的括号对。
	这里只需要搞清楚“合法(well-formed)”的概念就行了，那就是
	1.左右括号数相等
	2.任一位置之前的右括号数不大于左括号数

	有了这样两点，那么要生成括号对总数为n的所有可能性的串。就从空字符串开始，按照上面的第二点限制，逐步添加左右括号即可。
	当拿到合法的串，长度为k，时，要继续添加一个括号，那么就看这个串如果左括号的数目没有达到n，那就可以在此基础上添加一个左括号；
	同时，如果串内右括号数目小于左括号数目的话，还可以在k串上添加一个右括号。
	这样遍历了所有长度为k的合法串之后，我们就得到了所有合法的长度为k+1的串。
	当我们生成了所有长度为2n的合法串，就得到了答案。


	题目描述：Generate Parentheses
	Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
	For example, given n = 3, a solution set is:
	“((()))”, “(()())”, “(())()”, “()(())”, “()()()”

*/
void genPar(string s, int lc, int rc, int n, vector<string>& res)  
{  
    if (rc == n)  
    {      
        res.push_back(s);  
        return;  
    }  
          
    if (lc > rc)      
        genPar(s + ')', lc, rc + 1, n, res);  
          
          
    if (lc < n)  
        genPar(s + '(', lc + 1, rc, n, res);  
}
vector<string> generateParenthesis(int n){
	    // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        vector<string> res;  
        string s = "";  
        genPar(s, 0, 0, n, res);          
        return res;  
}  