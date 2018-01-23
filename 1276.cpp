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
int dp[110000],t[30000],n[1005],d[1005];
int main()
{
	//freopen("in","r",stdin);
   	//freopen("out","w",stdout);
	int cash,nn,k,cnt,i,j;
	while (scanf("%d%d",&cash,&nn)!=EOF)
	{
        for (i=0;i<nn;i++)
			scanf("%d%d",&n[i],&d[i]);
		
		memset(dp,0,sizeof(dp));
			
		cnt=0;
		for (i=0;i<nn;i++)
		{
			if (n[i]==0||d[i]==0)
				continue;
			k=1;
			while (k<n[i])
    		{
    			t[cnt++]=d[i]*k;
    			n[i]-=k;
    			k*=2;
    		}
			t[cnt++]=n[i]*d[i];
		}
  	
		for (i=0;i<cnt;i++)
			for (j=cash;j>=t[i];j--)
			{
				if (dp[j]<dp[j-t[i]]+t[i])
					dp[j]=dp[j-t[i]]+t[i];
			}
		printf("%d\n",dp[cash]);
	}
	return 0;
}
