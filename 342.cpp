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

__int64 h[150005],in[150005],out[150005];

int main()
{
	//freopen("in","r",stdin);
   	//freopen("out","w",stdout);
	__int64 n,w,he,sum,ans,i,max;
	
	while (scanf("%I64d%I64d%I64d",&n,&w,&he)!=EOF)
	{
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		memset(h,0,sizeof(h));
		sum=0;
		
		for (i=w+1;i<=n+w;i++)
		{
			scanf("%I64d",&h[i]);
			sum+=h[i];
		}
		if (w*he>sum)
		{
			printf("-1\n");
			continue;
		}
		else 
		{
			ans=(1ll<<62);
			for (i=1;i<=n+w*2;i++)
			{
				if (h[i]>=he)
				{
					out[i]=out[i-1]+h[i]-he;
					in[i]=in[i-1];
				}
				if (h[i]<=he)
				{
					out[i]=out[i-1];
					in[i]=in[i-1]+he-h[i];
				}
				max=(in[i]-in[i-w])>(out[i]-out[i-w])?(in[i]-in[i-w]):(out[i]-out[i-w]);
				if (i>=w && ans>max) ans=max;
			}
			printf("%I64d\n",ans);
		}	
	}
	return 0;
}
