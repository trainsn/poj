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
int father[50005];
int relation[50005];
int find(int x)
{
	if (x!=father[x])
	{
		int temp=father[x];
		father[x]=find(temp);
		relation[x]=(relation[x]+relation[temp])%3;
	}
	return father[x];
}
int main()
{
	//freopen("1182.in","r",stdin);
   	//freopen("1182.out","w",stdout);
	int n,m,i,cnt=0,d,x,y,fx,fy;
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		father[i]=i;
		relation[i]=0;
	}
	for (i=0;i<m;i++)
	{
		//cin>>d>>x>>y;
		scanf("%d %d %d",&d,&x,&y);
		if (x>n||y>n)
		{
			++cnt;
			continue;
		}
		if (d==2&&x==y)
		{
			++cnt;
			continue;
		}
		fx=find(x);
		fy=find(y);
		if (fx==fy)
		{
			if (d==1&&relation[x]!=relation[y])
			{
				++cnt;
				continue;
			}
			if (d==2&&relation[x]!=(relation[y]+2)%3)
			{
				++cnt;
				continue;
			}
		}
		else 
		{
			father[fy]=fx;
			relation[fy]=(relation[x]+d-1+3-relation[y])%3;
		}
	}
	cout<<cnt;
	return 0;
}
