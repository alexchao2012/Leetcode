#include"head.h"

class Stack{
public:
	Stack(int length){
		arr=new char[2*length];
		top=-1;
		capacity=2*length;
	}
	void push(char e){
		if(top==capacity){
			exit(1);
		}
		arr[++top]=e;
	}
	void pop(){
		if(top==-1)
			return;
		--top;
	}
	char getTop(){
		if(top!=-1)
			return arr[top];
		else
			return '#';
	}
	bool isEmpty(){
		return top==-1;
	}

	char *arr;
	int top;
	int capacity;
};

bool isMatched(char c1,char c2){
	switch(c1){
	case '(':
		if(c2==')')
			return true;
		else
			return false;
		break;
	case '[':
		if(c2==']')
			return true;
		else
			return false;
		break;
	case '{':
		if(c2=='}')
			return true;
		else
			return false;
		break;
	default:
		return false;
	}
}
bool isValid(string s){
	if(""==s)
		return true;

	int length=s.length();
	Stack stk(length);
	for(int i=0;i<length;i++){
		if(s[i]=='{' || s[i]=='[' || s[i]=='(')
			stk.push(s[i]);
		else if('}'==s[i] || ']'==s[i] || ')'==s[i]){
			if(stk.isEmpty())
				return false;
			else if(!isMatched(stk.getTop(),s[i]))
				return false;
			else
				stk.pop();
		}
		else
			return false;
	}
	if(stk.isEmpty())
		return true;
	else
		return false;
}

bool isValid1(string s){
	stack<char> buf;
	for(int i=0;i<s.length();i++){
		char c=s[i];
		if('{'==c || '['==c || '('==c)
			buf.push(c);
		else{
			if(buf.size()==0)
				return false;
			char top=buf.top();
			if(c=='}'){
				if(top!='{')
					return false;
			}
			else if(c==']'){
				if(top!='[')
					return false;
			}
			else if(c==')'){
				if(top!='(')
					return false;
			}
			buf.pop();
		}
	}
	return buf.size()==0;
}






