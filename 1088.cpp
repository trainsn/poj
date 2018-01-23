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

int mapp[105][105];
int cnt[105][105];
int r,c;

int dp(int i,int j)
{
	int max=0;
	if (cnt[i][j]>0)
	{
		return cnt[i][j];
	}
	
	if ((j-1>=0)&&(mapp[i][j]>mapp[i][j-1])&&(dp(i,j-1)>max)) max=dp(i,j-1);
	if ((j+1<=c-1)&&(mapp[i][j]>mapp[i][j+1])&&(dp(i,j+1)>max)) max=dp(i,j+1);
	if ((i-1>=0)&&(mapp[i][j]>mapp[i-1][j])&&(dp(i-1,j)>max)) max=dp(i-1,j);
	if ((i+1<=r-1)&&(mapp[i][j]>mapp[i+1][j])&&(dp(i+1,j)>max)) max=dp(i+1,j);
	return cnt[i][j]=max+1;
}
int main()
{
	freopen("1088.in","r",stdin);
   	freopen("1088.out","w",stdout);
	scanf("%d %d",&r,&c);
	int i,j;
	for (i=0;i<r;i++)
		for (j=0;j<c;j++)
		{
			scanf("%d",&mapp[i][j]);
			cnt[i][j]=0;
		}
	for (i=0;i<r;i++)
		for (j=0;j<c;j++)
			dp(i,j);
	int max=0;
	for (i=0;i<r;i++)
		for (j=0;j<c;j++)
			if (cnt[i][j]>max) max=cnt[i][j];
	printf("%d\n",max);
	return 0;
}
