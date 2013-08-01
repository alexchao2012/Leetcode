#include"stage2.h"
//fibonacci的打印还未解决
	//int n;
	//cin>>n;
	//int N=fibonacci(n);
	//vector<int> A;
	//A.push_back(1);
	//A.push_back(2);
	//vector<vector<int> > ret;
	//ret=combinationSum2(A,N);
	//for(int i=0;i<ret.size();++i){
	//	for(int j=0;j<ret[i].size();++j)
	//		cout<<ret[i][j]<<' ';
	//	cout<<endl;
	//}

void printSum(int candidates[], int index[], int n) {
  for (int i = 1; i <= n; i++)
    cout << candidates[index[i]] << ((i == n) ? "" : "+");
  cout << endl;
}
 
void solve(int target, int sum, int candidates[], int sz, int index[], int n) {
  if (sum > target)
    return;
  if (sum == target)
    printSum(candidates, index, n);
 
  for (int i = index[n]; i < sz; i++) {
    index[n+1] = i;
    solve(target, sum + candidates[i], candidates, sz, index, n+1);
  }
}
 
void solve(int target, int candidates[], int sz) {
  int index[10000];
  index[0] = 0;
  solve(target, 0, candidates, sz, index, 0);
}

void backTrack(vector<int> &candidates,vector<int> &index,int sum,int target,vector<vector<int> > &ret){
    if(sum>target)return;
	if(sum==target){
		vector<int> temp;
		for(int i=1;i<index.size();++i)
			temp.push_back(candidates[index[i]]);
		ret.push_back(temp);
        return;
	}
		 
	for(int i=index[index.size()-1];i<candidates.size();++i){
		index.push_back(i);
		backTrack(candidates,index,sum+candidates[i],target,ret);
        index.pop_back();
	}
}

vector<vector<int> > combinationSum2(vector<int> &candidates, int target){
	vector<int> index(1,0);
	vector<vector<int> > ret;
	sort(candidates.begin(),candidates.end());
	backTrack(candidates,index,0,target,ret);
	return ret;
}


    void calculate(vector<int> cache, int curIdx, vector<int>& candidates, vector<vector<int> >& res, int target)  
    {  
        if (curIdx >= candidates.size()) return;  
          
        int i = 0;  
        while (target - candidates[curIdx] * i >= 0)  
        {  
            for (int j = 0; j < i; ++j)   
            {  
                cache.push_back(candidates[curIdx]);                  
            }  
              
            if (target - candidates[curIdx] * i == 0)  
            {  
                res.push_back(cache);  
                break;  
            }  
                  
            calculate(cache, curIdx + 1, candidates, res, target - candidates[curIdx] * i);  
              
            for (int j = 0; j < i; ++j)   
            {  
                cache.pop_back();                  
            }  
              
            ++i;  
        }  
    }  
vector<vector<int> > combinationSum3(vector<int> &candidates, int target) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        vector<vector<int> > res;  
        vector<int> cache;  
        sort(candidates.begin(), candidates.end());  
        calculate(cache, 0, candidates, res, target);  
          
        return res;  
    }  
      
int fibonacci(int n){
	int f1=1,f2=2,f=0;

	if(n<=0) return 0;
	if(n<=2) return (n==1)?f1:f2;

	for(int i=0;i<n-2;++i){
		f=f1+f2;
		f1=f2;
		f2=f;
	}
	return f;
}
