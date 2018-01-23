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

struct Edge
{
	int x,y,w;
};
Edge e[500*500];
int father[500];
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
	int n,i,j,cnt,tmp,num,ans,test,tt; 
	cin>>test;
	for (tt=0;tt<test;tt++)
	{
		cnt=0;
	    cin>>n;
		for (i=0;i<n;i++)
		{
			father[i]=i;
			for (j=0;j<n;j++)
				if (scanf("%d",&tmp)&&i>j)
				{
					e[cnt].x=i;
					e[cnt].y=j;
					e[cnt].w=tmp;
					cnt++;
				}
		}
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
				if (e[i].w>ans) ans=e[i].w;
				if (++num==n-1) break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
