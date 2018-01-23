#include<cstdio>
#include<iostream>
const int MOD=10000;
struct matrix
{
	int m[2][2];
}ans,base;
matrix multi(matrix x,matrix y)
{
	matrix tmp;
	int i,j,k;
	for (i=0;i<2;i++)
	{
		for (j=0;j<2;j++)
		{
			tmp.m[i][j]=0;
			for (k=0;k<2;k++)
			{
				tmp.m[i][j]=(tmp.m[i][j]+x.m[i][k]*y.m[k][j])%MOD;
			}
		}
	}
	return tmp;
}
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n;
    while (scanf("%d",&n)&&n!=-1)
	{
		ans.m[0][0]=ans.m[1][1]=1;
		ans.m[1][0]=ans.m[0][1]=0;
		
		base.m[0][0]=base.m[0][1]=base.m[1][0]=1;
		base.m[1][1]=0;
		while (n)
		{
			if (n&1) ans=multi(ans,base);
			base=multi(base,base);
			n>>=1;
		}
		printf("%d\n",ans.m[0][1]);
	}
}
