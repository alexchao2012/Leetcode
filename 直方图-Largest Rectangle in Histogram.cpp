#include"stage2.h"
/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
The largest rectangle is shown in the shaded area, which has area = 10 unit.
For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

int largestRectangleArea2(vector<int> &height) {  //单调栈
    // Start typing your C/C++ solution below  
    // DO NOT write int main() function  
    int q[100000] = {-1};  
    int w[100000];  
          
    int res = 0;  
    int top = 0;  
    for (int i = 0; i <= height.size(); ++i)  
    {  
        int h;  
        i == height.size() ? h = 0: h = height[i];  
              
        if (h > q[top])  
        {  
            q[++top] = h;  
            w[top] = 1;  
        }  
        else  
        {  
            int cnt = 0;  
            while (h <= q[top])  
            {  
                res = max(res, (w[top] + cnt) * q[top]);  
                cnt += w[top--];  
            }  
            q[++top] = h;  
            w[top] = cnt + 1;  
        }  
    }  
    return res;  
}

int largestRectangleArea1(vector<int> &height) { //类似于trapping rain water 
    if(0 == height.size())  
        return 0;  
    vector<int> leftLimit(height.size());  
    stack<int> limits;  
    for(int i = 0; i < height.size(); ++i)  
    {  
        while(!limits.empty())  
        {  
            if(height[limits.top()] >= height[i])  
                limits.pop();  
            else  
                break;  
        }  
        if(limits.empty())  
            leftLimit[i] = -1;  
        else  
            leftLimit[i] = limits.top();  
        limits.push(i);  
    }  
  
    while(!limits.empty()) limits.pop();  
  
    vector<int> rightLimit(height.size());  
    for(int i = height.size() - 1; i >= 0; --i)  
    {  
        while(!limits.empty())  
        {  
            if(height[limits.top()] >= height[i])  
                limits.pop();  
            else  
                break;  
        }  
        if(limits.empty())  
            rightLimit[i] = height.size();  
        else  
            rightLimit[i] = limits.top();  
        limits.push(i);  
    }  
  
    int ret = 0;  
    int temp = 0;  
    for(int i = 0; i < height.size(); ++i)  
    {  
        temp = (rightLimit[i] - leftLimit[i] - 1)*height[i];  
        if(temp > ret)  
            ret = temp;  
    }  
  
    return ret;  
}

struct pairs{
    int h;
	int w;
	pairs(int _h,int _w):h(_h),w(_w){}
};

int largestRectangleArea(vector<int> &height) {//对
	vector<int> &H=height;
	if(H.size()==0)return 0;
	int n=H.size(),maxValue=INT_MIN,curMax;
	stack<pairs> stk;
	stk.push(pairs(-1,0));
	for(int i=0;i<=n;++i){
        if(i==n)H[i]=0;
		if(H[i]>stk.top().h)
			stk.push(pairs(H[i],1));
		else{
			int cnt=0;
			while(stk.top().h>=H[i]){
				curMax=stk.top().h*(stk.top().w+cnt);
				if(curMax>maxValue)maxValue=curMax;
				cnt+=stk.top().w;
				stk.pop();
			}
			stk.push(pairs(H[i],cnt+1));
		}
	}
	return maxValue;
}

	
		