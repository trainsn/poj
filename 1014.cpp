#include <iostream>  
#include <stdio.h>  
#include <memory.h>  
using namespace std;
int main()
{
	//freopen("1014.in","r",stdin);
   	//freopen("1014.out","w",stdout);
	int va,sum,i,j,n[11],count=0,w[11];
	int bag[120005],v[1005],total;
	while(scanf("%d %d %d %d %d %d", &n[0],&n[1],&n[2],&n[3],&n[4],&n[5]))
	{
		va=0;
		for (i=0;i<6;i++)
		{
			w[i]=i+1;
			va+=w[i]*n[i];
		}
		if (!va) break;
		count++;
		printf("Collection #%d:\n",count);
		if (va%2==1) 
		{
			printf("Can't be divided.\n\n");
			continue;
		}
		sum=va/2;total=0;
		for (i=0;i<6;i++)
		{
			if (n[i]==0) continue;
			for (j=1;j<=n[i];j*=2)
			{
				v[total++]=j*w[i];
				n[i]-=j;
			}
			v[total++]=n[i]*w[i];
		}
		memset(bag,0,sizeof(bag));
		for (i=0;i<total;i++)
			for (j=sum;j>=v[i];j--)
				bag[j]=max(bag[j],bag[j-v[i]]+v[i]);
		if (bag[sum]!=sum) 
			printf("Can't be divided.\n\n");
		else 
			printf("Can be divided.\n\n");	
	}
	return 0;
}
