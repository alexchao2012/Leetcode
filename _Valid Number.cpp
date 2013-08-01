#include"stage2.h"

/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
*/
bool isInteger(const char* s, int begin, int end) ;
	bool isDecimal(const char* s, int begin, int end)  ;
bool isNumber(const char *s) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        if (s == NULL) return false;  
        if (strlen(s) == 0) return false;  
          
        int begin = 0;  
        int end = strlen(s) - 1;  
        while (s[begin] == ' ') ++begin;  
        while (s[end] == ' ') --end;  
  
        if (begin > end) return false;  
          
        int idx = begin;  
        while (idx <= end)  
        {  
            if (s[idx] == 'e' || s[idx] == 'E')  
                return isDecimal(s, begin, idx - 1) && isInteger(s, idx + 1, end);  
            ++idx;  
        }  
          
        return isDecimal(s, begin, end);  
    }  
      
    bool isDecimal(const char* s, int begin, int end)  
    {  
        if (begin <= end)  
        {  
            int idx = begin;  
            bool hasDot = false;  
            bool hasDigit = false;  
            if (s[idx] == '+' || s[idx] == '-')  
                ++idx;  
            while (idx <= end)  
            {  
                if (s[idx] >= '0' && s[idx] <= '9')  
                {  
                    ++idx;  
                    hasDigit = true;  
                    continue;  
                }  
                else if (s[idx] == '.')  
                {  
                    if (!hasDot)  
                    {  
                        ++idx;  
                        hasDot = true;  
                        continue;  
                    }  
                    else  
                        return false;  
                }  
                else  
                    return false;  
                  
            }  
            return hasDigit;  
        }  
        return false;  
    }  
      
    bool isInteger(const char* s, int begin, int end)  
    {  
        if (begin <= end)  
        {  
            int idx = begin;  
            bool hasDigit = false;  
            if (s[idx] == '+' || s[idx] == '-')  
                ++idx;  
            while (idx <= end)  
            {                  
                if (s[idx] >= '0' && s[idx] <= '9')  
                {  
                    ++idx;  
                    hasDigit = true;  
                }  
                else  
                    return false;  
     
            }  
            return hasDigit;  
        }  
          
        return false;  
    }  
	    bool isNumber2(const char *s) {
        if (s == NULL || s[0] == '\0') return false;
        bool cansign = true;
        bool cane = false;
        bool havee = false;
        bool candot = true;
        bool onlyspace = false;
        bool havenum = false;
        bool numbegin = false;
        while(*s != '\0') {
            char c = *(s++);
            if (c == ' '){
                if (numbegin)
                    onlyspace = true;
                continue;//skip space
            } else if (onlyspace) {
                return false;
            }
            if (c == '+' || c == '-') {
                if(!cansign) return false;
                cansign = false;
                numbegin = true;
                continue;
            }
            if (c == 'e') {
                if(!cane) return false;
                cane = false;
                havenum = false;
                numbegin = true;
                cansign = true;
                havee = true;
                candot = false;
                continue;
            }
            if (c == '.') {
                if(!candot) return false;
                candot = false;
                numbegin = true;
                cansign = false;
                continue;
            }
            if (c >= '0' && c <= '9') {
                havenum = true;
                numbegin = true;
                cansign = false;
                if(!havee) cane = true;
            } else {
                return false;
            }
        }
        return havenum;
    }