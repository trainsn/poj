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
int dp[25][16000];
int c[25],g[25];
int main()
{
	//freopen("in","r",stdin);
   	//freopen("out","w",stdout);
	int cc,gg,i,j,k;
	scanf("%d%d",&cc,&gg);	
	for (i=1;i<=cc;i++)
		scanf("%d",&c[i]);
	for (i=1;i<=gg;i++)
		scanf("%d",&g[i]);
	
	memset(dp,0,sizeof(dp));
	dp[0][7500]=1;
	
	for (i=1;i<=gg;i++)
		for (j=0;j<=15000;j++)
			if (dp[i-1][j])
			{
				for (k=1;k<=cc;k++)
					dp[i][j+g[i]*c[k]]+=dp[i-1][j];
			}
	printf("%d\n",dp[gg][7500]);
	return 0;
}
