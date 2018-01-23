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
int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	freopen("1125.in","r",stdin);
   	freopen("1125.out","w",stdout);
	int n,m,dis,b,d[105][105],max,mind,ans,i,j,k;
	while (1)
	{	
		scanf("%d",&n);
        if (n==0) break; 
        memset(d,7,sizeof(d));
		//memset(f,100000,sizeof(f));
		for (i=1;i<=n;i++)
		{
			cin>>m;
			d[i][i]=0;
			for (j=1;j<=m;j++)
			{
				cin>>b>>dis;
				d[i][b]=dis;
			}
		}
			
		for (k=1;k<=n;k++)
			for (i=1;i<=n;i++)
				for (j=1;j<=n;j++)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		mind=d[0][0]+1;
		for (i=1;i<=n;i++)
		{
			max=0;
			for (j=1;j<=n;j++)
				if ((d[i][j]>max))
					max=d[i][j];
			if (max<mind) 
			{
				mind=max;
				ans=i;
			}
		}
		cout<<ans<<" "<<mind<<endl;
	}
	
	return 0;
}
