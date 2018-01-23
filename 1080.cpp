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

string s1,s2;
const int matrix[5][5]=
{{5,-1,-2,-1,-3}, 
{-1,5,-3,-2,-4},
{-2,-3,5,-2,-2},
{-1,-2,-2,5,-1},
{-3,-4,-2,-1,0}
};
map<char,int> dic;
int dp[110][110]; 

int main()
{
	//freopen("in","r",stdin);
   	//freopen("out","w",stdout);
	int test,len1,len2,i,j;
	
	dic['A']=0;
	dic['C']=1;
	dic['G']=2;
	dic['T']=3;
	dic['-']=4;
	cin>>test;
	while (test--)
	{
		cin>>len1>>s1;
		cin>>len2>>s2;
		for (i=len1;i>=1;i--)
		{
			s1[i]=s1[i-1];
		}
		for (i=len2;i>=1;i--)
		{
			s2[i]=s2[i-1];
		}
		memset(dp,0,sizeof(dp));
		for (i=1;i<=len1;i++)
		{
			dp[i][0]=matrix[dic[s1[i]]][4]+dp[i-1][0];
		}
		for (j=1;j<=len2;j++)
		{
			dp[0][j]=matrix[4][dic[s2[j]]]+dp[0][j-1];
		}
		for (i=1;i<=len1;i++)
			for (j=1;j<=len2;j++)
			{
				dp[i][j]=dp[i-1][j-1]+matrix[dic[s1[i]]][dic[s2[j]]];
				dp[i][j]=max(dp[i][j],dp[i-1][j]+matrix[dic[s1[i]]][4]);
				dp[i][j]=max(dp[i][j],dp[i][j-1]+matrix[4][dic[s2[j]]]);
			}
		printf("%d\n",dp[len1][len2]);
	}
	return 0;

}
