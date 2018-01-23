#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>

using namespace std;
char s[5005]; 
short dp[5005][5005];
int min1(int a,int b,int c)
{
	int t=a<b?a:b;
	t=t<c?t:c;
	return t;
}
int min2(int e,int f)
{
	int t=e<f?e:f;
	return t;
}

int main()
{
	//freopen("1159.in","r",stdin);
   	//freopen("1159.out","w",stdout);
	int n,i,j,k,g; 
	scanf("%d",&n);
	scanf("%s",s+1);
	for (i=1;i<=n;i++)
		dp[i][i]=0;
	for (j=1;j<=n-1;j++)
		for (k=1;k<=n-j;k++)
		{
			g=k+j;
			if (s[g]==s[k]) 
				dp[k][g]= min1(dp[k+1][g-1],dp[k+1][g]+1,dp[k][g-1]+1);
			else 
				dp[k][g]=min2(dp[k+1][g]+1,dp[k][g-1]+1);
		}	
	printf("%d\n",dp[1][n]);
	return 0;
}
