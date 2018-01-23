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
struct node
{
	int val,pos;
}f[500005];
int n;

bool cmp(node a,node b)
{
	return a.val<b.val;
}
int reflect[500005],c[500005];
int lowbit(int x)
{
	return x & (-x);
}
void update(int x)
{
	while (x<=n)
	{
		c[x]++;
		x+=lowbit(x);
	}
}

int getsum(int x)
{
	int sum=0;
	while (x>0)
	{
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}

int main()
{
	freopen("in","r",stdin);
   	freopen("out","w",stdout);
   	int i;
	while (scanf("%d",&n) &&n )
	{
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		
		long long ans=0;
		
		for (i=1;i<=n;i++)
		{
			scanf("%d",&f[i].val);
			f[i].pos=i;
		}
		sort(f+1,f+n+1,cmp);
		for (i=1;i<=n;i++)
			reflect[f[i].pos]=i;
		for (i=1;i<=n;i++)
		{
			update(reflect[i]);
			ans+=i-getsum(reflect[i]);
		}
		printf("%lld\n",ans);	
	}		
	return 0;
}
