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
	int l,r,c;
}q[100005];
int fa[20005],h[20005];

int cmp(node a,node b)
{
	return a.c>b.c;
}
int getf(int x)
{
	if (fa[x]==x) return x;
	fa[x]=getf(fa[x]);
	return fa[x];
}

void un(int x,int y)
{
	int xx,yy;
	xx=getf(x);
	yy=getf(y);
	if (xx!=yy)
		fa[xx]=yy;
}

int main()
{
	freopen("in","r",stdin);
   	freopen("out","w",stdout);
	int n,m,i,tl,tr;
	scanf ("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		fa[i]=i;
	memset(h,0,sizeof(h));
	for (i=0;i<m;i++)
	{
		scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].c);
	}
	sort(q,q+m,cmp);
	for (i=0;i<m;i++)
	{
		tl=getf(q[i].l);
		tr=getf(q[i].r);
		if (tl==tr)
		{
			printf("%d\n",q[i].c);
			return 0;
		}
		if (h[q[i].l]==0&&h[q[i].r]==0)
		{
			h[q[i].l]=q[i].r;
			h[q[i].r]=q[i].l;
			continue;
		}
		if (h[q[i].l]==0)
		{
			h[q[i].l]=q[i].r;
			//continue;
		}
		if (h[q[i].r]==0)
		{
			h[q[i].r]=q[i].l;
			//continue;
		}
		un(h[q[i].l],q[i].r);
		un(h[q[i].r],q[i].l);
	}
	printf("0");
	return 0;
}
