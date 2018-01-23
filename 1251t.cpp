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
int fa[5005];
int n,m,p,i,a,b;
int getf(int x)
{
	if  (fa[x]==x) return x;
	//else 
	{
		fa[x]=getf(fa[x]);
		return fa[x];
	}
}
int main()
{
	freopen("in","r",stdin);
   	freopen("out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&p);
	for (i=1;i<=n;i++)
		fa[i]=i;
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		fa[getf(a)]=getf(b);
	}
	for (i=1;i<=p;i++)
	{
		scanf("%d%d",&a,&b);
		if (getf(a)==getf(b))
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
