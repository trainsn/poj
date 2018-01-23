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
#define LL long long
string s;
int dp[105][105],value[105][105];
void print(int i,int j)
{
	if (i>j) return ;
	else if (i==j)
	{
		if (s[i]=='(' ||s[i]==')') printf("()");
		if (s[i]=='[' ||s[i]==']') printf("[]");
	}
	else 
		if (value[i][j]==-1)
		{
			printf("%c",s[i]);
			print(i+1,j-1);
			printf("%c",s[j]);
		}
	else 
	{
		print(i,value[i][j]);
		print(value[i][j]+1,j);
	}
	return ;
}
int main()
{
	freopen("in","r",stdin);
   	freopen("out","w",stdout);
	int len,i,j,p,k,n;
	cin>>n;
	while (n--)
	{
	cin>>s;
	cin>>s;
	memset(dp,0,sizeof(dp));
	len=s.length();
	for (i=0;i<len;i++)
		dp[i][i]=1;
	for (p=1;p<len;p++)
		for (i=0;i<len-p;i++)
		{
			j=i+p;
			dp[i][j]=214748367;
			if ((s[i]=='(' && s[j]==')') || (s[i]=='[' &&s[j]==']'))
			{
				dp[i][j]=dp[i+1][j-1];
				value[i][j]=-1;
			}
			for (k=i;k<j;k++)
				if (dp[i][j]>dp[i][k]+dp[k+1][j])
				{
					dp[i][j]=dp[i][k]+dp[k+1][j];
					value[i][j]=k;
				}
		}
	print(0,len-1);
	printf("\n");
	printf("\n");
	}
	return 0;

}
