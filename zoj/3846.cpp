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

int a[100005];
int gcd(int a,int b )
{
	if (b) return gcd(b,a%b);
	return a;
}
int main()
{
	//freopen("in","r",stdin);
   	//freopen("out","w",stdout);
	
	int cas=1,n;
	while (~scanf("%d",&n))
	{
		for (int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		printf("Case %d: ",cas++);
		int tmp=a[0];
		for (int i=1;i<n;i++)
		{
			tmp=gcd(tmp,a[i]);
		}
		if (tmp!=1)
		{
			printf("-1\n\n");
			continue;
		}
		else 
		{
			printf("%d\n",2*n-2);
			for (int i=2;i<=n;i++)
				printf("1 %d\n",i);
			for (int i=2;i<=n;i++)
				printf("1 %d\n",i);
			cout<<endl;
		}
	}
	return 0;
}
