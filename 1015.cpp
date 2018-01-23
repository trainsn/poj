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
struct node
{
	int p;
	int d;
	int s;
	int v;
}pre[210];
int path[25][810],dp[25][810];
int id[25];
bool selete(int j,int k,int i)
{
	while(j>0&&path[j][k]!=i)
	{
		k-=pre[path[j][k]].v;
		j--;
	}
	if (j==0) return 1;
	else return 0;
}
int main()
{
	freopen("in","r",stdin);
   	freopen("out","w",stdout);
	int t=0,n,m;
	while (cin>>n>>m && n)
	{
		memset(pre,0,sizeof(pre));
		memset(dp,-1,sizeof(dp));
		memset(path,0,sizeof(path));
		
		for (int i=1;i<=n;i++)
		{
			scanf("%d %d",&pre[i].p,&pre[i].d);
			pre[i].s=pre[i].p+pre[i].d;
			pre[i].v=pre[i].p-pre[i].d;
		}	
		
		int fix=m*20;	
		dp[0][fix]=0;
		
		for (int i=1;i<=m;i++)
			for (int k=0;k<=2*fix;k++)
				if (dp[i-1][k]>=0)
					for (int j=1;j<=n;j++)
						if (dp[i-1][k]+pre[j].s>dp[i][k+pre[j].v]&&selete(i-1,k,j))
						{
							dp[i][k+pre[j].v]=dp[i-1][k]+pre[j].s;
							path[i][k+pre[j].v]=j;
						}
		int k;
		for (k=0;k<=fix;k++)
		{
			if (dp[m][fix+k]>=0||dp[m][fix-k]>=0)
				break;
		}
		
		int div=dp[m][fix+k]>dp[m][fix-k]?(fix+k):(fix-k);
		int D=(dp[m][div]-div+fix)/2;
		int P=(dp[m][div]+div-fix)/2;
		printf("Jury #%d\n", ++t);  
        printf("Best jury has value %d for prosecution and value %d for defence:\n", P, D);  
        
		int j=m;k=div;
		for (int i=0;i<=m;i++)
		{
			id[i]=path[j][k];
			k-=pre[path[j][k]].v;
			j--;
		}
		sort(id,id+m);
		for (int i=0;i<m;i++)
		{
			printf(" %d",id[i]);
		}
		printf("\n\n");
	}
	
	return 0;
}
