#include"head.h"

vector<vector<int> > threeSum(vector<int> &num){
	vector<vector<int> > res;
	if(num.size()<3)
		return res;
	sort(num.begin(),num.end());

	int i,j,k;
	vector<int> temp(3);
	for(i=0;i<num.size()-2;i++){
		k=i+1;
		j=num.size()-1;
		while(k<j){
			int sum=num[i]+num[k]+num[j];
			if(sum==0){
				temp[0]=num[i];//这里使用新的临时变量会超界
				temp[1]=num[k];
				temp[2]=num[j];
				res.push_back(temp);
				--j;
				++k;
			}
			else if(sum>0)
				--j;
			else
				++k;
		}
	}
	sort(res.begin(),res.end());
	res.erase(unique(res.begin(),res.end()),res.end());
	return res;
}

			