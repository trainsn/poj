#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<set>
#include<queue>
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
#define LL long long
#define maxn 310
#define eps 1e-6

int dp[maxn][maxn][9][9];
int n;

int range(int x)
{
	return (int)(log2(x)+eps);
}
void initrmq()
{
	int i,j;
	int k=range(n);
	int r,c;
	for (i=0;i<=k;i++)
	{
		for (j=0;j<=k;j++)
		{
			if (!i&&!j) continue;
			for (r=1;r+(1<<i)-1<=n;r++)
			{
				for (c=1;c+(1<<j)-1<=n;c++)
				{
					if (i==0&&j!=0)
					{
						dp[r][c][i][j]=min(dp[r][c][i][j-1],dp[r][c+(1<<(j-1))][i][j-1]);
					}
					else if (i!=0)
					{
						dp[r][c][i][j]=min(dp[r][c][i-1][j],dp[r+(1<<(i-1))][c][i-1][j]);
					}
				}
			}
		}
	}
}
int query(int x1,int y1,int x2,int y2)
{
	int t1=range(x2-x1+1);
	int t2=range(y2-y1+1);
	int a,b,c,d;
	a=dp[x1][y1][t1][t2];
	b=dp[x2-(1<<t1)+1][y1][t1][t2];
	c=dp[x1][y2-(1<<t2)+1][t1][t2];
	d=dp[x2-(1<<t1)+1][y2-(1<<t2)+1][t1][t2];
	return min(min(a,b),min(c,d));
}
int main()
{
	//freopen("in","r",stdin);
   	//freopen("out","w",stdout);
	int test;
	scanf("%d",&test);
	while (test--)
	{
		scanf("%d",&n);
		int i,j;
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			{
				scanf("%d",&dp[i][j][0][0]);
			}
		}
		initrmq();
		int m;
		scanf("%d",&m);
		while (m--)
		{
			int x1,x2,y1,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			printf("%d\n",query(x1,y1,x2,y2));
		}
	}
	return 0;
}
