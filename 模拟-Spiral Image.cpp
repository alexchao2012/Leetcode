#include"stage2.h"

vector<int> spiralOrder(vector<vector<int> > &matrix){
    vector<int> ret;
	int m=matrix.size();//���ﲻ��ͬʱ�ж�m��n����m=0����matrix[0]���������ڣ��ʲ���������
	
	if(m>0){
		int n=matrix[0].size();
		if(n>0){
			for(int i=0;i<min(m,n)/2;++i){
				for(int j=i;j<n-i-1;++j)
					ret.push_back(matrix[i][j]);
				for(int j=i;j<m-i-1;++j)
					ret.push_back(matrix[j][n-i-1]);
				for(int j=n-i-1;j>i;--j)// Ҫע���ǲ���ȥ������Ҫ����ƽ���
					ret.push_back(matrix[m-i-1][j]);
				for(int j=m-i-1;j>i;--j)
					ret.push_back(matrix[j][i]);
			}
			int layer=min(m,n)/2;
			if(min(m,n)%2==1){
				if(m>n)//����������Ҫ�����Ԫ����ʲô��
					for(int i=layer;i<=m-layer-1;++i)
						ret.push_back(matrix[i][layer]);
				else
					for(int i=layer;i<=n-layer-1;++i)
						ret.push_back(matrix[layer][i]);
			}
		}
	}
	return ret;
}

void spiralPrint(int m,int n){
	if(m<=0 || n<=0)return;

	int **ret=new int*[m];
	for(int i=0;i<m;++i){
		ret[i]=new int[n];
		memset(ret[i],0,sizeof(int)*n);//memset���÷���ע��Բ�κ�����void *memset(void *dest,char c,size_t count);
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



