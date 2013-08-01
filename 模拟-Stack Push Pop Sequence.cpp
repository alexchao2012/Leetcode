#include<iostream>
#include<stack>

using namespace std;

bool isPopSequence(int *Push,int *Pop,int n){
	if(Push==NULL || Pop==NULL || n<0) return false;

	stack<int> stk;

	int pushIndex=0,popIndex=0;
	while(popIndex<n){//判断条件别写错了~
		while(stk.empty() || stk.top()!=Pop[popIndex]){
			if(pushIndex>=n)
				break;
			stk.push(Push[pushIndex++]);
		}

		if(stk.top()!=Pop[popIndex])
			break;

		stk.pop();
		++popIndex;
	}

	if(stk.empty() && popIndex==n)
		return true;

	return false;
}

//int main(){
//	int pop[]={1,2};
//	int push[]={1,2};
//
//	cout<<isPopSequence(push,pop,2);
//
//	return 0;
//}