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

int main()
{
	freopen("in","r",stdin);
   	freopen("out","w",stdout);
	double vs,r,c,x,ans,w;
	int i,n;
	scanf("%lf%lf%lf%d",&vs,&r,&c,&n);
	for (i=0;i<n;i++)
	{
		scanf("%lf",&w);
		x=r*c*w;
		ans=x*vs*sqrt(1/(1+x*x));
		printf("%.3lf\n",ans);
	}
	return 0;
}
