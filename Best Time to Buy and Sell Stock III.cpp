#include"stage3.h"
/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).
*/
int maxProfit(vector<int> &prices) {
        // null check
        int len = prices.size();
        if (len==0) return 0;

        vector<int> historyProfit;
        vector<int> futureProfit;
        historyProfit.assign(len,0);
        futureProfit.assign(len,0);
        int valley = prices[0];
        int peak = prices[len-1];
        int maxProfit = 0;

        // forward, calculate max profit until this time
        for (int i = 0; i<len; ++i)
        {
            valley = min(valley,prices[i]);
            if(i>0)
            {
                historyProfit[i]=max(historyProfit[i-1],prices[i]-valley);
            }
        }

        // backward, calculate max profit from now, and the sum with history
        for (int i = len-1; i>=0; --i)
        {
            peak = max(peak, prices[i]);
            if (i<len-1)
            {
                futureProfit[i]=max(futureProfit[i+1],peak-prices[i]);
            }
            maxProfit = max(maxProfit,historyProfit[i]+futureProfit[i]);
        }
        return maxProfit;
}

int maxProfit2(vector<int> &prices) {
	int f[3] = {0};
	int g[3] = {0};

	int n = prices.size() - 1;
	for (int i = 0; i < n; ++i) {
		int diff = prices[i+1] - prices[i];
		int m = min(i+1, 2);
		for (int j = m; j >= 1; --j) {
			f[j] = max(f[j], g[j-1]) + diff;
			g[j] = max(g[j], f[j]);
		}
	}
	return max(g[1], g[2]);
}
