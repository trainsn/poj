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

/*int  max(int a,int b)
{
	return a>b?a:b;
}*/
int main()
{
	//freopen("in","r",stdin);
   	//freopen("out","w",stdout);
	int f,v,dp[106][105],w[105][105];
	scanf("%d %d",&f,&v);
	for (int i=1;i<=f;i++)
		for(int j=1;j<=v;j++)
		{
			scanf("%d",&w[i][j]);
		}
	memset(dp,0,sizeof(dp));
	dp[1][1]=w[1][1];
	for (int i=2;i<=f;i++)
		dp[1][i]=max(dp[1][i],w[1][i]);
	for (int i=1;i<=f;i++)
		for (int j=i+1;j<=v;j++)
		{
			/*if (i==j) 
				dp[i][j]=dp[i-1][j-1]+w[i][j];
			else */
				dp[i][j]=max(dp[i-1][j-1]+w[i][j],dp[i][j-1]);
		}
	cout<<dp[f][v];
	return 0;
}
