#include"stage2.h"

#define MAXN 1000

void dummy(int *A,int n){
	for(int i=0;i<n-1;++i)
		cout<<A[i]<<' ';
	cout<<A[n-1]<<endl;
}

void backTrack(int *A,int n,int m,int len,int *temp,bool *checked){
	int i;
	if(len==m)
		dummy(temp,m);
	else
		for(i=0;i<n;++i)
			if(!checked[i]){
				temp[len]=A[i];
				checked[i]=true;
				backTrack(A,n,m,len+1,temp,checked);
				checked[i]=false;
			}
}

void genPerm(int n,int m){
	assert(n>0 && m>0);
	int A[MAXN],temp[MAXN];
	bool checked[MAXN];
	memset(checked,false,sizeof(checked));
	for(int i=0;i<n;++i)
		A[i]=i+1;
	backTrack(A,n,m,0,temp,checked);
}

void backTrack(vector<int> num,int n,int m,int len,int *index,bool *checked,vector<vector<int> > &ret){
	int i;
	if(len==n){
		vector<int> tmp;
		for(int i=0;i<n;++i)
			tmp.push_back(num[index[i]]);
		ret.push_back(tmp);
		//return;
	}
	else
		for(i=0;i<n;++i)
			if(!checked[i]){
				index[len]=i;
				checked[i]=true;
				backTrack(num,n,m,len+1,index,checked,ret);
				checked[i]=false;
			}
}

vector<vector<int> > permutations(vector<int> num){//5�����Ĳ��Լ�ͨ����
	vector<vector<int> > ret;
	if(num.size()<=1){
		ret.push_back(num);
		return ret;
	}

	int n=num.size();
	int *index=new int[n];
	bool *checked=new bool[n];
	memset(checked,false,sizeof(checked));
	int m=n;//����ȫ���У�����ΪС��n������Ϊ����n��Ԫ����ȡ��m����ȫ����
	backTrack(num,n,m,0,index,checked,ret);
	delete [] index;
	delete [] checked;
	return ret;
}