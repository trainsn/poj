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
const int MOD=1000000007;
#define LL long long
char str[105];
int a[105];
int tab[20];
int len;

int tran(char c)
{
	if (c=='A') return 0;
	else if (c=='0') return 9;
	else if (c>='2' && c<='9') return c-'1';
	else if (c=='J') return 10;
	else if (c=='Q') return 11;
	else if (c=='K') return 12;
}
LL gao(int p,int eq,int _sum,int tab[])
{
	LL ret=0;
	if (p==len)
	{
		if (eq==1) return 0;
	}
	if (_sum==0 && p)
	{
		return 1;
	}
	if (eq==0)
	{
		ret=1;
		for (int i=0;i<=12;++i)
		{
			ret=(ret*Cm())
		}
	}
}
int main()
{
	//freopen("in","r",stdin);
   	//freopen("out","w",stdout);
	while (scanf("%s",str)!=EOF)
	{
		memset(a,-1,sizeof(a));
		memset(tab,0,sizeof(tab));
		len=0;
		int l=strlen(str);
		for (int i=0;i<l;++i)
		{
			if (str[i+1]=='0')
			{
				a[len++]=tran('0');
				++i;
			}
			else 
				a[len++]=tran(str[i]);
			++tab[a[len-1]];
		}
		int _sum=0;
		for (int i=0;i<=12;++i)
		{
			tab[i]=4-tab[i];
			_sum+=tab[i];
		}
		printf("%lld\n",gao(0,1,_sum,tab));
	}
	return 0;
}
