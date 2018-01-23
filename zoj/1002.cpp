#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<set>
#include<queue>
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
#define LL long long

int map[5][5],n,ans,num;
int find(int i,int j)
{
	for (int k=i+1;(map[k][j]!=1 && k<n);k++)
		if (map[k][j]==2) return 0;
	for (int k=i-1;(map[k][j]!=1 && k>=0);k--)
		if (map[k][j]==2) return 0;			
	for (int k=j+1;(map[i][k]!=1 && k<n);k++)
		if (map[i][k]==2) return 0;
	for (int k=j-1;(map[i][k]!=1 && k>=0);k--)
		if (map[i][k]==2) return 0;
	return 1;
}
void dfs()
{
	if (num>ans)
	{
		ans=num;
	}
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (!map[i][j]&&find(i,j))
			{
				num++;
                map[i][j]=2;
				dfs();
				num--;
				map[i][j]=0;
			}
}
int main()
{
	freopen("in","r",stdin);
   	freopen("out","w",stdout);
	char c;
	
	while (1)
	{
		cin>>n;
		if (n==0) break;
        memset(map,0,sizeof(map));
		ans=0;
		for (int i=0;i<n;i++)
		{
            scanf("%c",&c);
			for (int j=0;j<n;j++)
			{
				scanf("%c",&c);
				if (c=='X') 
				{
					map[i][j]=1;
				}
			}
        } 
        num=0;
		dfs();		
		cout<<ans<<endl;
	}
	return 0;
}
