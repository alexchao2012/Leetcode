#include"stage2.h"

bool isMatch9(const char *s, const char *p) {  //非递归解法
    // Start typing your C/C++ solution below  
    // DO NOT write int main() function  
    const char *str, *pat;  
    bool star = false;  
          
    for (str = s, pat = p; *str != '\0'; ++str, ++pat)  
    {  
        switch(*pat)  
        {  
            // 遇到'?',那么不管*str是任何字母都能匹配  
            case '?':  
                break;  
            case '*':  
                star = true;  
                // 暂时忽略‘*’  
                s = str, p = pat;  
                do  
                {  
                    ++p;  
                }while(*p == '*');  
                    // 如果'*'之后，pat是空的，直接返回true  
                if (!*p)  
                    return true;  
                // 重新开始匹配  
                str = s - 1;  
                pat = p - 1;  
                break;  
            default:  
                if (*str != *pat)  
                {  
                    // 如果前面没有'*'，则匹配不成功  
                    if (!star)  
                        return false;  
                    // 从s的下一位和'*'之后的p重新开始匹配  
                    ++s;  
                    str = s - 1;  
                    pat = p - 1;  
                }  
                break;  
        }  
    }  
          
    while (*pat == '*')  
        ++pat;  
    return (!*pat);  
} 

bool isMatch(const char *s, const char *p){
	const char *s1=s,*p1=p;
	while(*s1){
		switch(*p1){
		case '?':
			if(*s1=='\0')return false;
			break;
		case '*':
			do{++p1;}while(*p1=='*');
			if(!*p1)return true;
			while(*s1)if(isMatch(s1++,p1))return true;
			return false;
		default:
			if(*s1!=*p1)return false;
			break;
		}
		++p1,++s1;
	}
	while(*p1=='*')++p1;
	return !*p1;
}

bool isMatch11(const char *s,const char *p){
	while(*s){
		if(*s==*p)++p,++s;
		else if(*p=='?'){
			if(*s=='\0')return false;
			++p,++s;
		}
		else if(*p=='*'){
			do{++p;}while(*p=='*');
			if(!*p)return true;
			while(*s)
				if(isMatch11(s++,p))return true;
			return false;
		}
		else return false;
	}
	while(*p=='*')++p;
	return !*p;
}
