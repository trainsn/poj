#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int test,n,i;
	long long   a[105];
	scanf("%d",&test);
	while (test--)
	{
		scanf("%d",&n);	
		for (i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+n+1);
		if(a[1]!=a[2])
			printf("%lld\n",a[1]);
		else 
			printf("%lld\n",a[n]);
	}
	return 0;
}
