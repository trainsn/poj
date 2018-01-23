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

int main()
{
	//freopen("in","r",stdin);
   	//freopen("out","w",stdout);
	int max,i,t,st,en,step,ans;
	while(scanf("%d %d",&st,&en)!=EOF)
	{
		max=0;
		cout<<st<<" "<<en;
		if (st>en)
		{
			t=st;st=en;en=t;
		}
		for (i=st;i<=en;i++)
		{
			t=i;
			step=1;
			while (t!=1)
			{
				if (t%2==1)
					t=t*3+1;
				else 
					t/=2;
				step++;
			}
			if (step>max)
			{
				max=step;
				ans=i;
			}
		}
		printf(" %d\n",max); 
	}
	return 0;
}
