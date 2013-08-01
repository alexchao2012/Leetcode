#include"stage2.h"
/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, � , ak) must be in non-descending order. (ie, a1 ? a2 ? � ? ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    return combinationSum(num,target);
        
}
vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector<vector<int> > ret;
    if(candidates.size()==0)
        return ret;
        
    sort(candidates.begin(),candidates.end());
    vector<int> path;
        
    dfs(0,0,candidates,target,path,ret);
        
    return ret;
        
}
    
void dfs(int curSum,int pos,vector<int> &candidates,int target,vector<int> path,vector<vector<int> > &ret){
    if(curSum>target)return;
    if(curSum==target){
        ret.push_back(path);
        return;
    }
        
    for(int i=pos;i<candidates.size();++i){
        path.push_back(candidates[i]);
        dfs(curSum+candidates[i],i+1,candidates,target,path,ret);
        path.pop_back();
        while(i+1 < candidates.size() && candidates[i] == candidates[i+1])
            ++i;
    }
}