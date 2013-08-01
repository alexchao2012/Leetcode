#include"head.h"

int threeSumClosest(vector<int> &num, int target){
	sort(num.begin(),num.end());
	int diff=INT_MAX;
	int res=0;

	int i,j,k;
	for(i=0;i<num.size()-2;i++){
		j=i+1;
		k=num.size()-1;
		while(j<k){
			int temp=num[i]+num[j]+num[k];
			if(temp==target)
				return target;
			else if(temp>target){
				if(diff>temp-target){
					diff=temp-target;
					res=temp;
				}
				--k;
			}
			else{
				if(diff>target-temp){
					diff=target-temp;
					res=temp;
				}
				++j;
			}
		}
	}
	return res;
}


