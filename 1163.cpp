#include<iostream>

using namespace std;

int main()
{
	freopen("1163.in","r",stdin);
   	freopen("1163.out","w",stdout);
	int n,i,max,j;
    int a[105][105]={0};
    int f[105][105]={0};
	scanf("%d",&n);
	//memset(a,0,sizeof(a));
	//memset(f,0,sizeof(f));
	for (i=1;i<=n;i++)
	    for (j=1;j<=i;j++)
	{
		scanf("%d",&a[i][j]);
	}
	f[1][1]=a[1][1];
	for (i=2;i<=n;i++)
	    for (j=1;j<=i;j++)
	{
		if (f[i-1][j-1]>f[i-1][j]) f[i][j]=f[i-1][j-1]+a[i][j]; 
		else f[i][j]=f[i-1][j]+a[i][j]; 
	}
	max=0;
	for (i=1;i<=n;i++)
		if (f[n][i]>max) max=f[n][i];
	printf("%d\n",max);
	return 0;
}
