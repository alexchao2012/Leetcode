#include"stage3.h"
/*
Given a string, determine if it is a palindrome, 
considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good 
question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/
bool isAlphanumeric(char c){
	return (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9');
}

char getNormalizedChar(char c){
	return (c>='A' && c<='Z')?('a'+(c-'A')):c;
}

bool isPalindrome(string s){
	if(s.size()==0)return true;

	int left=0,right=s.size()-1;

	while(left<right){
		while(!isAlphanumeric(s[left]) && left<s.size())
			++left;
		while(!isAlphanumeric(s[right]) && right>=0)
			--right;

		if(left<right){
			if(getNormalizedChar(s[left])!=getNormalizedChar(s[right]))
				return false;
			++left;
			--right;
		}
	}
	return true;
}

//int main(){
//	cout<<isPalindrome(string())<<endl;
//
//	return 0;
//}