#include<iostream>

using namespace std;

int searchMin(int A[],int n){
	if(A==NULL || n<0) return -1;

	int left=0,right=n-1;
	while(left<=right){
		int mid=left+((right-left)>>1);

		if(A[mid]<A[right])
			right=mid;
		else if(A[mid]>A[right])
			left=mid+1;
		else
			--right;
	}

	return A[left];
}

//int main(){
//	int A[]={1,1,1,1,2,2};
//	int n=6;
//	cout<<searchMin(A,n)<<endl;
//
//	int x=192;
//	cout<< (x^(x & (x-1)));
//
//	return 0;
//}