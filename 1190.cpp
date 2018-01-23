#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
const int inf=1000000007;
#define LL long long

int minv[25],mins[24],best,v,m;

void dfs(int depth,int sumv,int sums,int r,int h)//r为当前的半径，h为当前层的高度
{
	if (depth==0)
	{
		if (sumv==v&&sums<best)
			best=sums;
		return;
	}
	if (sumv+minv[depth-1]>v||sums+mins[depth-1]>best||sums+2*(v-sumv)/r>=best)
	{
		return;
	}
	
	for (int i=r-1;i>=depth;i--)
	{
		if (depth==m)
		{	
			sums=i*i;
		}
		int maxh=min((v-sumv-minv[depth-1])/(i*i),h-1);
		for (int j=maxh;j>=depth;j--)
			dfs(depth-1,sumv+i*i*j,sums+2*i*j,i,j);
	}		
}
int main()
{
	//freopen("in","r",stdin);
   	//freopen("out","w",stdout);
   	
	cin>>v;//v
	cin>>m;//depth
	int rmax=(int)sqrt((double)v);
	int hmax=v;
	best=inf;
	minv[0]=mins[0]=0;
	for (int i=1;i<=m;i++)
	{
		mins[i]=mins[i-1]+2*i*i;
		minv[i]=minv[i-1]+i*i*i;
	}
	dfs(m,0,0,rmax,hmax);
	if (best==inf)
		cout<<"0"<<endl;
	else 
		cout<<best<<endl;
	return 0;
}
