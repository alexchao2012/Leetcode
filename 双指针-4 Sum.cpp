#include"head.h"

vector<vector<int> > fourSum(vector<int> &num, int target){
	vector<vector<int> > res;
	if(num.size()<4)
		return res;
	vector<int> temp(4);

	sort(num.begin(),num.end());
	int i,j,k,l;
	for(i=0;i<num.size()-3;i++){
		for(j=i+1;j<num.size()-2;j++){
			k=j+1;
			l=num.size()-1;
			while(k<l){
				int t=num[i]+num[j]+num[k]+num[l];
				if(t==target){
					temp[0]=num[i];
					temp[1]=num[j];
					temp[2]=num[k];
					temp[3]=num[l];
					res.push_back(temp);
					++k;
					--l;
				}
				else if(t>target)
					--l;
				else
					++k;
			}
		}
	}
	sort(res.begin(),res.end());
	res.erase(unique(res.begin(),res.end()),res.end());
	return res;
}