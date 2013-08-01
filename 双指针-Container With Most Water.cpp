#include"head.h"

int maxArea(vector<int> &height){
	if(height.size()<2)
		return 0;

	int i=0,j=height.size()-1;
	int maxArea=0,area=0;

	while(i<j){
		if(height[i]<height[j]){
			area=height[i]*(j-i);
			++i;
		}
		else{
			area=height[j]*(j-i);
			--j;
		}
		maxArea=max(maxArea,area);
	}
	return maxArea;
}
