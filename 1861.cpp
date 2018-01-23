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
struct node
{
	int x,y,len; 
}e[15005];
int father[1005],ansx[1005],ansy[1005];

int find(int x)
{
	if (father[x]!=x)
		father[x]=find(father[x]);
	return father[x];
}
bool cmp(node a,node b)
{
	return a.len<b.len;
}
int main()
{
	//freopen("in","r",stdin);
   	//freopen("out","w",stdout);
	int i,m,n,t=0,num,ans;
	cin>>n>>m;

	for (i=0;i<n;i++)
		father[i]=i;
	for (i=0;i<m;i++)
	{
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].len);
	}
	sort(e,e+m,cmp);
	num=0;ans=0;
	for (i=0;i<m;i++)
	{
		int a,b;
		a=find(e[i].x);
		b=find(e[i].y);
		if (a!=b)
		{
			father[a]=b;
			if (e[i].len>ans) 
			{
				ans=e[i].len;				
			}
			num++;
			if (num==n)
				break;
			ansx[num]=e[i].x;
			ansy[num]=e[i].y;
		}
	}
	cout<<ans<<endl;
	cout<<num<<endl;
	for (i=1;i<=num;i++)
		printf("%d %d\n",ansx[i],ansy[i]);
	return 0;
}
