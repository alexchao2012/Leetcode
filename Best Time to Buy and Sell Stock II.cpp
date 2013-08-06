#include"stage3.h"
/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times). However, you may not engage
in multiple transactions at the same time
(ie, you must sell the stock before you buy again).
*/
int maxProfit6(vector<int> &prices) {
    int p = 0;
    for(int i = 1; i < prices.size() ; ++i) {
        int delta = prices[i] - prices[i-1];
        if(delta > 0 ) {
            p += delta;
        }
    }
    return p;
}

int maxProfit7(vector<int>&prices) { //找到最多的递增子序列个数，然后统计其总利润！
	if (prices.size() == 0)	return 0; 

	int start = prices[0]; 
	int profit = 0;

	for(int i = 1; i < prices.size(); i++){
		if (prices[i] >= prices[i-1]) continue;
		profit += prices[i-1] - start;
		start = prices[i]; 
	}

	profit += prices[prices.size()-1] - start; 
	return profit;
}

// solution structure
struct Interval
{
    int buy;
    int sell;
};
 
// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n)
{
    // Prices must be given for at least two days
    if (n == 1)
        return;
 
    int count = 0; // count of solution pairs
 
    // solution vector
    Interval *sol=new Interval[n/2 + 1];	
 
    // Traverse through given price array
    int i = 0;
    while (i < n-1)
    {
        // Find Local Minima. Note that the limit is (n-2) as we are
        // comparing present element to the next element. 
        while ((i < n-1) && (price[i+1] <= price[i]))
            i++;
 
        // If we reached the end, break as no further solution possible
        if (i == n-1)
            break;
 
        // Store the index of minima
        sol[count].buy = i++;
 
        // Find Local Maxima.  Note that the limit is (n-1) as we are
        // comparing to previous element
        while ((i < n) && (price[i] >= price[i-1]))
            i++;
 
        // Store the index of maxima
        sol[count].sell = i-1;
 
        // Increment count of buy/sell pairs
        count++;
    }
 
    // print solution
    if (count == 0)
        printf("There is no day when buying the stock will make profit\n");
    else
    {
       for (int i = 0; i < count; i++)
          printf("Buy on day: %d\t Sell on day: %d\n", sol[i].buy, sol[i].sell);
    }
 
    return;
}