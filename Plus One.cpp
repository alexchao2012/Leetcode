#include"head.h"
/*
Given a number represented as an array of digits, 
plus one to the number.
*/

vector<int> plusOne3(vector<int> &digits){//更简洁一些，复杂度没有量级改变，就要把代码写的简洁
	if(digits.size()==0)return digits;
	int carry=1;
	for(int i=digits.size()-1;i>=0;--i){
		int sum=digits[i]+carry;
		carry=sum/10;
		digits[i]=sum%10;
	}
	if(carry)
		digits.insert(digits.begin(),1);
	return digits;
}

vector<int> plusOne(vector<int> &digits) {
    int overflow = 1;
    for(int i = digits.size() - 1; i >= 0; --i) {
        int dsum = digits[i] + overflow;
        overflow = dsum / 10;
        digits[i] = dsum % 10;
    }
    if(overflow) {
        digits.insert(digits.begin(),1);
    }
    return digits;
}

 vector<int> plusOne1(vector<int> &digits) {
	if(digits.size()==0)return digits;
	digits[digits.size()-1]+=1;
	int n=(int)digits.size();

	for(int i=n-1;i>0;--i){
		if(digits[i]>=10){
			digits[i]-=10;
			digits[i-1]+=1;
		}
		else return digits;
	}

	if(digits[0]>=10){
		digits[0]-=10;
		digits.insert(digits.begin(),1);
		return digits;
	}
	else return digits;
 }
