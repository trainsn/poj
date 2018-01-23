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
	int l,w;
}stick[5005];
bool use[5005];
bool operator  < (const node a,const node b)
{
	if (a.l==b.l)
		return a.w<b.w;
	return a.l<b.l;
}
int main()
{
	freopen("in","r",stdin);
   	freopen("out","w",stdout);
   	int test,n; 
  	cin>>test;
	while (test--)
	{
		memset(use,0,sizeof(use));
		scanf("%d",&n);
		int count=0;
		node last;
		for (int i=0;i<n;i++)
		{
			scanf("%d%d",&stick[i].l,&stick[i].w);
		}
		sort(stick,stick+n);
		for (int i=0;i<n;i++)
		{
			if (!use[i])
			{
				last.w=stick[i].w;
                for (int j=i+1;j<n;j++)
				{
					if (last.w<=stick[j].w&&!use[j])
					{
						use[j]=1;
						last.w=stick[j].w;
					}
				}
				count++;
			}
			
		}
		cout<<count<<endl;
	}
	return 0;
}
