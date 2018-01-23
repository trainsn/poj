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
int num[50005],dp[50005];
int main()
{
	freopen("in","r",stdin);
   	freopen("out","w",stdout);
   	int test,n; 
	while (scanf("%d",&n) && n)
	{
		int sum=0;
		int max=-999999,ans;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			sum+=num[i];
			if (sum>max)
			{
				max=sum;
			}
			dp[i]=max;
			if (sum<0) sum=0;
		}
		ans=max=-999999;
		sum=0;
		for (int i=n-1;i>=1;i--)
		{
			sum+=num[i];
			if (sum>max)
				max=sum;
			if (max+dp[i-1]>ans)
				ans=max+dp[i-1];
			if (sum<0)
				sum=0;
		}
		cout<<ans<<endl;
	}

	
	return 0;
}
