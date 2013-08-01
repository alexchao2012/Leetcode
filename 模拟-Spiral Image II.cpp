#include"stage2.h"

void spiralPrint(int m,int n){
	if(m<=0 || n<=0)return;

	int **ret=new int*[m];
	for(int i=0;i<m;++i){
		ret[i]=new int[n];
		memset(ret[i],0,sizeof(int)*n);//memset的用法，注意圆形函数：void *memset(void *dest,char c,size_t count);
	}   
	//memset(ret,0,sizeof(int)*m*n);
	int cnt=1;

	for(int layer=0;layer<min(m,n)/2;++layer){
		for(int j=layer;j<n-layer-1;++j,++cnt)
			ret[layer][j]=cnt;
		for(int j=layer;j<m-1-layer;++j,++cnt)
			ret[j][n-layer-1]=cnt;
		for(int j=n-layer-1;j>layer;--j,++cnt)
			ret[m-layer-1][j]=cnt;
		for(int j=m-layer-1;j>layer;--j,++cnt)
			ret[j][layer]=cnt;
	}
	int layer=min(m,n)/2;
	if(1==min(m,n)%2){
		if(m>n)
			for(int i=layer;i<=m-layer-1;++i,++cnt)
				ret[i][layer]=cnt;
		else
			for(int i=layer;i<=n-layer-1;++i,++cnt)
				ret[layer][i]=cnt;
	}

	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j)
			cout<<ret[i][j]<<'\t';
		cout<<endl;
	}

	for(int i=0;i<m;++i)
		delete [] ret[i];
	delete [] ret;
}