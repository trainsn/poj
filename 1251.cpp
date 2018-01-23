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
#define LL long long
struct Edge
{
	int x,y,w;
}e[100];
int father[100]; 
int find(int x)
{
	if (father[x]!=x)
		father[x]=find(father[x]);
	return father[x];
}
bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
int main()
{
	freopen("in","r",stdin);
   	freopen("out","w",stdout);
	
	int n,m,i,j,num,ans,cnt,l,len;
	char cx,cy;
	while (scanf("%d",&n) && n)
	{
		cnt=0;
		
		for (i=0;i<n-1;i++)
		{
			scanf("%d",&cx);
			scanf("%c %d",&cx,&l);
			father[cx-'A']=cx-'A';			
			for (j=0;j<l;j++)
			{
				scanf("%c",&cy);
				scanf("%c %d",&cy,&len);
				e[cnt].x=cx-'A';
				e[cnt].y=cy-'A';
				e[cnt].w=len;	
				cnt++;		
			}
		}
		father[n-1]=n-1;
		
		sort(e,e+cnt,cmp);
		num=0;ans=0;
		for (i=0;i<cnt;i++)
		{
			int a,b;
			a=find(e[i].x);
			b=find(e[i].y);
			if (a!=b)
			{
				father[a]=b;
				ans+=e[i].w;
				if (++num==n-1) break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
