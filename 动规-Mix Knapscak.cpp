#include<iostream>
#include<vector>

using namespace std;

int knapsack(int v[],int w[],int c[],int n,int W){
	if(!v || !w || !c || n<=0 || W<=0) return 0;

	vector<vector<int> > dp(W+1,vector<int>(n+1,INT_MIN));
	dp[0][n]=0;

	for(int j=n-1;j>=0;--j){
		for(int i=0;i<=W;++i){ 
			for(int k=0;k<=c[j];++k){
				if(i<k*w[j]) break;

				int tmp=dp[i-k*w[j]][j+1];
				if(tmp!=INT_MIN){
					tmp+=k*v[j];

					if(tmp>dp[i][j])
						dp[i][j]=tmp;					
				}
			}
		}
	}

	return dp[W][0];
}

//int main(){
//	int n,W;
//	cout<<"input n W"<<endl;
//
//	while(cin>>n>>W){
//		int *v=new int [n];
//		int *w=new int[n];
//		int *c=new int[n];
//
//		for(int i=0;i<n;++i){
//			cout<<"input v[i]	w[i] c[i]"<<endl;
//			cin>>v[i]>>w[i]>>c[i];
//		}
//
//		cout<<knapsack(v,w,c,n,W);
//	}
//
//	return 0;
//}