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
const int maxn=100007;
const int maxk=32;
int n,p,ans; 
int sum[maxn][maxk],c[maxn][maxk];
int head[maxn],next[maxn],v[maxn],ecount;

int hash(int c[])
{
	int ret=0,i;
	for (i=0;i<p;i++)
	{
		ret=((ret<<2)+(c[i]>>4))^(c[i]<<10);
	}
	ret=(ret%maxn+maxn)%maxn;
	return ret;
}
void addedge(int a,int b)
{
	next[ecount]=head[a];
	head[a]=ecount;
	v[ecount]=b;
	ecount++;
}
int main()
{
	//freopen("in","r",stdin);
   	//freopen("out","w",stdout);
	memset(sum,0,sizeof(sum));
	memset(c,0,sizeof(c));
	memset(head,-1,sizeof(head));
	int i,j,k,a,h;
	bool ok;
	
	scanf("%d%d",&n,&p);
	ecount=0;ans=0;
	addedge(hash(c[0]),0);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a);
		for (j=0;j<p;j++)
		{
			sum[i][j]=sum[i-1][j]+(1&a);
			a=a>>1;
		}
		for (j=0;j<p;j++)
			c[i][j]=sum[i][j]-sum[i][0];
		h=hash(c[i]);
		for (j=head[h];j!=-1;j=next[j])
		{
			ok=1;
			for (k=0;k<p;k++)
				if (c[v[j]][k]!=c[i][k])
				{
					ok=0;
					break;
				}
			if (ok&&ans<i-v[j])
				ans=i-v[j];
		}
		addedge(h,i);
	}
	printf("%d\n",ans);
	return 0;
}
