#include <stdio.h>
#include<cstdlib>
int a[10],b[10];
void merge(int st,int en)
{
	if (st==en) return;
	int mid;
	mid=(st+en)/2;
	merge(st,mid);
	merge(mid+1,en);
	int i=st,j=mid+1,k=st;
	while (k!=en+1)
	{
		if (a[i]<a[j]&&i!=mid+1||j==en+1)
		{
			b[k++]=a[i];
			i++;		
		}
		else 
		{
			b[k++]=a[j];
			j++;
		}
	}
	for (i=st;i<=en;i++)
	{
		a[i]=b[i];
	}
}
int main(void)
{
	
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	int i,j;
	int n;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	merge(0,n-1);
	for (i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
