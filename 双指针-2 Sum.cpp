#include"head.h"

struct pair1{
	int data;
	int index;
	bool operator<(const pair1 &rhs)const{
		return data<rhs.data;
	}
};



vector<int> twoSum(vector<int> &numbers,int target){
	vector<int> res;
	vector<pair1> arr(numbers.size());
	for(int i=0;i<numbers.size();i++){
		arr[i].data=numbers[i];
		arr[i].index=i;		
	}

	sort(arr.begin(),arr.end());

	int i=0;
	int j=arr.size()-1;
	while(i<j){
		if(arr[i].data+arr[j].data>target)
			--j;
		else if(arr[i].data+arr[j].data<target)
			++i;
		else{
			int index1=min(arr[i].index,arr[j].index)+1;
			res.push_back(index1);
			int index2=max(arr[i].index,arr[j].index)+1;
			res.push_back(index2);
			return res;	
		}
		
	}
}

vector<int> twoSum2(vector<int> &numbers,int target){
    vector<int> ret;
	if(numbers.size()<=1)
		return ret;
	
	vector<pair<int,int> > arr;
	for(int i=0;i<numbers.size();++i)		
		arr.push_back(make_pair(numbers[i],i));
	sort(arr.begin(),arr.end());
	int i=0,j=arr.size()-1;
	while(i<j){
		int sum=arr[i].first+arr[j].first;
		if(sum==target){
			ret.push_back(min(arr[i].second,arr[j].second)+1);
			ret.push_back(max(arr[i].second,arr[j].second)+1);
			return ret;
		}
		else if(sum>target)
			--j;
		else 
			++i;
	}
}