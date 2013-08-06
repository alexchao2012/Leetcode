#include"head.h"
/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ¡­
1 is read off as ¡°one 1¡å or 11.
11 is read off as ¡°two 1s¡± or 21.
21 is read off as ¡°one 2, then one 1¡å or 1211.
Given an integer n, generate the nth sequence.
Note: The sequence of integers will be represented as a string.

The previous version of code is mistake by understanding the question. That at each point in the sequence, we have to count the repeat count of same character in the pre sequence.

For example: when n == 5, the sequence is 111221.
Then , when n == 6, we have to say Three-1s,Two-2s and One-1, that is: 312211.
With this understanding, we can achieve the right code above.



But, there is a interesting things, that the repeat character cannot exceeds 3 times. Why?
Why could not see the sequence like ¡°41¡å, that means the previous sequence must be like ¡°x1111y¡±. There are only two ways to translating the meaning of this sequence:
1. x-1s, one-1, one-y, obviously, this is not valid, because, in this case, we could leading to ¡°(x+1)11y¡±
2. some-xs, one-1, one-1, y-someelses, like above, this leading to ¡°x21y¡±
Thus, the character ¡¯4¡ä, can never be a part of the sequence no matter how large the n is.
*/

    string countAndSay1(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 0) return "";
        string s = "1";
        for(int ir = 2; ir <= n; ++ir) {
            string t;
            for(int i = 0; i < s.size(); ++i) {
                char curc = s[i];
                int countc = 1;
                for(int j = i + 1; j < s.size() && s[j] == curc; ++j) {
                    ++countc;
                    ++i;
                }
                if(countc > 3) cout<<"!!!";
                t += ('0' + countc);
                t += curc;
            }
            s = t;
        }
        return s;
    }

string countAndSay2(int n){
	if(n<=0)return "";
	string s("1");
	for(int i=1;i<n;++i){
		string t;
		for(int i=0;i<s.size();++i){
			char c=s[i];
			int cnt=1;
			for(int j=i+1;j<s.size() && s[j]==c;++j){
				++cnt;
				++i;
			}
			t+=cnt+'0';
			t+=c;
		}
		s=t;
	}
	return s;
}


string int2Str(unsigned num)  
{  
    stringstream oss;  
    while(num > 0)  
    {  
        oss << (char)('0' + num%10);  
        num /= 10;  
    }  
    string ret = oss.str();  
    if(0 == ret.size())  
        return "0";  
    reverse(ret.begin(), ret.end());  
    return ret;  
}
string getnext(string str)  
{  
    char ch = str[0];  
    int cnt = 1;  
    stringstream oss;  
    for(int i = 1; i < str.size(); ++i)  
    {  
        if(str[i] == ch)  
            ++cnt;  
        else  
        {  
            oss << int2Str(cnt);  
            oss << ch;  
            ch = str[i];  
            cnt = 1;  
        }  
    }  
    oss << int2Str(cnt);  
    oss << ch;  
    return oss.str();  
} 
string countAndSay(int n) {  
    string ret("1");  
    for(int i = 1; i < n; ++i)  
        ret = getnext(ret);  
    return ret;  
}  
      
 
  
 