#include"stage3.h"
/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction 
(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/
int maxProfit1(vector<int>&prices) { //始终维护最小值，然后是获得最大值！巧，需要领悟
	int maxVal = 0; 
	int minVal = INT_MAX; 
	for( int i = 0; i < prices.size(); i++){ 
		if(prices[i] < minVal) minVal = prices[i]; 
		maxVal = max(maxVal, prices[i]-minVal); 
	}
	return maxVal; 
}

int maxProfit2(vector<int> &prices) {
    if (prices.size() == 0)
        return 0;
            
    int maxPrice = prices[prices.size()-1];
    int ans = 0;
    for(int i = prices.size() - 1; i >= 0; i--)
    {
        maxPrice = max(maxPrice, prices[i]);
        ans = max(ans, maxPrice - prices[i]);
    }
        
    return ans;
}

int maxProfit5(vector<int> &prices) {//超时，技术太烂！
	if(prices.size()<2)return 0;
	int diff=INT_MIN;

	for(int i=0;i<prices.size()-1;++i)
		for(int j=i+1;j<prices.size();++j)
			diff=max(prices[j]-prices[i],diff);

	return diff;
}