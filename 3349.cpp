#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
const int k=14997;
struct node 
{
	int floor[7];
}snow[15000][100];
int m[15000];
bool solve(node a,node b)
{
	sort(a.floor,a.floor+6);
	sort(b.floor,b.floor+6);
	for (int i=0;i<6;i++)
	{
		if (a.floor[i]!=b.floor[i])
			return false;
	}
	return true;
}
int main()
{
	//freopen("in","r",stdin);
   	//freopen("out","w",stdout);
	node pp;
	int i,j,n,sum;
	while (~scanf("%d",&n))
	{
		memset(m,0,sizeof(m));
		//memset(snow,0,sizeof(snow));
		bool ok=0;
		for (i=0;i<n;i++)
		{
			sum=0;
			for (j=0;j<6;j++)
			{
				scanf("%d",&pp.floor[j]);
				sum=(sum+pp.floor[j])%k;
			}
			if (ok==0)
			{
				for (j=0;j<m[sum];j++)
				{
					if (solve(pp,snow[sum][j]))
					{
						ok=1;
						break;
					}
				}
				snow[sum][m[sum]]=pp;
				m[sum]++;
			}
		}
		if (ok)
			printf("Twin snowflakes found.\n");
		else 
			printf("No two snowflakes are alike.\n");
	}
	
	return 0;
}
