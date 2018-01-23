#include<stdio.h>
#include<iostream>
using namespace std;
int main(void)
{
	freopen("1046.in", "r", stdin);
	freopen("1046.out", "w", stdout);
	int r[20],b[20],g[20],rr,gg,bb,i,ansr,ansg,ansb,dis,min;
	for (i=0;i<16;i++)
	{
		scanf("%d %d %d",&r[i],&g[i],&b[i]);
	}
	while (1)
	{
		scanf("%d %d %d",&rr,&gg,&bb);
		if ((rr==-1)&&(gg==-1)&&(bb==-1))
			break;
		min=214748367;
		for (i=0;i<16;i++)
		{
			dis=(r[i]-rr)*(r[i]-rr)+(g[i]-gg)*(g[i]-gg)+(b[i]-bb)*(b[i]-bb);
			if (dis<min)				
			{
				min=dis;
				ansr=r[i];ansg=g[i];ansb=b[i];
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",rr,gg,bb,ansr,ansg,ansb);
	}
	return 0;
}
