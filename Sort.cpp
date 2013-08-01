#include"head.h"

//typedef ListNode *heapType;

int left(int i){
	return (i<<1)+1;//这里注意加上括号，否则优先级会出问题
}
int right(int i){
	return ((i+1)<<1);
}
void swap(int *a,int *b){
	*a=*a^*b;
	*b=*a^*b;
	*a=*a^*b;
}
void heapIfy(int arr[],int n,int i){
	int largest=i;
	if(left(i)<n && arr[left(i)]>arr[i])
		largest=left(i);
	if(right(i)<n && arr[right(i)]>arr[largest])
		largest=right(i);
	if(i!=largest){
		swap(&arr[i],&arr[largest]);
		heapIfy(arr,n,largest);
	}
}

void buildHeap(int arr[],int n){
	for(int i=n/2-1;i>=0;--i)
		heapIfy(arr,n,i);
}

void heapSort(int arr[],int n){
	buildHeap(arr,n);
	for(int i=n-1;i>0;--i){
		swap(&arr[0],&arr[i]);
		heapIfy(arr,i,0);
	}
}