#include<stdio.h>
#include<iostream>
using namespace std;

int a[200005],c[200005];

int lowbit(int x)
{
	return x&-x;
}
int getsum(int x)
{
	int i,sum=0;
	for (i=x;i;i-=lowbit(i))
	{
		sum+=c[i];
	}
	return sum;
}
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n,m,i,j,l,r,z;
	double ans;
	scanf("%d",&n);
	memset(c,0,sizeof(c));
	
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for (j=i;j<=n;j+=lowbit(j))
		{
			c[j]+=a[i];
		}
	}
	scanf("%d",&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		ans=(getsum(r)-getsum(l-1))*3.14;
		printf("%.2lf\n",ans);
		z=(l+r)/2;
		for (j=z;j<=n;j+=lowbit(j))
		{
			c[j]-=a[z];
		}
	}
	
	return 0;
}
