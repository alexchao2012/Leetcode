#include"stage2.h"

bool isMatch9(const char *s, const char *p) {  //�ǵݹ�ⷨ
    // Start typing your C/C++ solution below  
    // DO NOT write int main() function  
    const char *str, *pat;  
    bool star = false;  
          
    for (str = s, pat = p; *str != '\0'; ++str, ++pat)  
    {  
        switch(*pat)  
        {  
            // ����'?',��ô����*str���κ���ĸ����ƥ��  
            case '?':  
                break;  
            case '*':  
                star = true;  
                // ��ʱ���ԡ�*��  
                s = str, p = pat;  
                do  
                {  
                    ++p;  
                }while(*p == '*');  
                    // ���'*'֮��pat�ǿյģ�ֱ�ӷ���true  
                if (!*p)  
                    return true;  
                // ���¿�ʼƥ��  
                str = s - 1;  
                pat = p - 1;  
                break;  
            default:  
                if (*str != *pat)  
                {  
                    // ���ǰ��û��'*'����ƥ�䲻�ɹ�  
                    if (!star)  
                        return false;  
                    // ��s����һλ��'*'֮���p���¿�ʼƥ��  
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
