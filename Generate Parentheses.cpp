#include"head.h"
/*
	���ɺϷ������Ŷԡ�
	����ֻ��Ҫ��������Ϸ�(well-formed)���ĸ�������ˣ��Ǿ���
	1.�������������
	2.��һλ��֮ǰ������������������������

	�����������㣬��ôҪ�������Ŷ�����Ϊn�����п����ԵĴ����ʹӿ��ַ�����ʼ����������ĵڶ������ƣ�������������ż��ɡ�
	���õ��Ϸ��Ĵ�������Ϊk��ʱ��Ҫ�������һ�����ţ���ô�Ϳ��������������ŵ���Ŀû�дﵽn���ǾͿ����ڴ˻��������һ�������ţ�
	ͬʱ�����������������ĿС����������Ŀ�Ļ�����������k�������һ�������š�
	�������������г���Ϊk�ĺϷ���֮�����Ǿ͵õ������кϷ��ĳ���Ϊk+1�Ĵ���
	���������������г���Ϊ2n�ĺϷ������͵õ��˴𰸡�


	��Ŀ������Generate Parentheses
	Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
	For example, given n = 3, a solution set is:
	��((()))��, ��(()())��, ��(())()��, ��()(())��, ��()()()��

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