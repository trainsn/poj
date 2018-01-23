#include <cstdio>
#include <iostream>
const int maxlongint=214748367;
int f[10015],p[505],w[505];
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int test,n,E,F,i,j,v;
	scanf("%d",&test);
	while (test--)
	{
		scanf("%d%d",&E,&F);
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%d%d",&p[i],&w[i]);
		}
		v=F-E;
		f[0]=0;
		for (i=1;i<=v;i++)
			f[i]=maxlongint;
		for (i=1;i<=n;i++)
			for (j=0;j<=v;j++)
			{
				if (j-w[i]>=0)
					if (f[j-w[i]]+p[i]<f[j])
						f[j]=f[j-w[i]]+p[i];
			}
		if (f[v]==maxlongint)
			printf("This is impossible.\n");
		else 
			printf("The minimum amount of money in the piggy-bank is %d.\n",f[v]);
	}
}

