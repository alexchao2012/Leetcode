#include"head.h"

/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 �� 1,3,2
3,2,1 �� 1,2,3
1,1,5 �� 1,5,1
*/

void reverse(vector<int> &num,int start,int end){
	while(start < end){
		swap(num[start],num[end]);
		++start;
		--end;
	}
}

void nextPermutation(vector<int> &num) {
	if(num.size()<=1) return;

	int i=num.size()-2;
	while(i>=0 && num[i]>=num[i+1])
		--i;

	if(i >= 0){
		int j=num.size()-1;
		while(j>i && num[j]<=num[i])
			--j;

		swap(num[i],num[j]);

		reverse(num,i+1,num.size()-1);
	}
	else
		reverse(num,0,num.size()-1);
}
