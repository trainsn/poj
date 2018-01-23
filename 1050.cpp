#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<cmath>
using namespace std;

int sum[105]={0},a[105][105];
int main()
{
	freopen("1050.in","r",stdin);
   	freopen("1050.out","w",stdout);
   	int max,n,i,j,ans,k,sum1; 
	while(scanf("%d",&n)!=EOF)
	{	
		memset(a,0,sizeof(a));
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		
		ans=-99999;
		for (i=1;i<=n;i++)
		{			
			memset(sum,0,sizeof(sum));
			for (j=i;j<=n;j++)	
			{
				sum1=0;
				max=-99999;
				//calulate the sum of the kth column  from the ith row to the jth row  
				for (k=1;k<=n;k++)
					sum[k]+=a[j][k];	
				
				//then we can solve the problem by the algorithm of one-dimensional problem
				for (k=1;k<=n;k++)
				{
					if (sum1>0) sum1+=sum[k];//if the previous is positive then it may be in the answer
					else sum1=sum[k];//else we just drop it and resrart from sum[k]
					if (sum1>max) max=sum1; 
				}
				if (max>ans)ans=max;		
			}
		}
		printf("%d\n",ans);
	}
		
	return 0;
}
