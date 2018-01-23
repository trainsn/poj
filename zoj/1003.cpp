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
bool flag1,flag2;
void dfs(int a,int b,int num)
{
	if (a==1&&b==1)
	{
		flag1=1;
		flag2=1;
		return;
	}
	if (b==1)
		flag2=1;
	if (flag1)
		return;
	if (num==1)
		return;
	if (a%num==0)
		dfs(a/num,b,num-1);
	if (b%num==0)
		dfs(a,b/num,num-1);
	dfs(a,b,num-1);
}
int main()
{
	freopen("in","r",stdin);
   	freopen("out","w",stdout);
	int a,b,ans;
   	while (scanf("%d%d",&a,&b)!=EOF)
	{
		if (a<b)
		{
			a=a^b;
			b=a^b;
			a=a^b;
		}	
		flag1=flag2=0;
		dfs(a,b,100);
		if (flag1==1||flag2==0)
			ans=a;
		else 
			ans=b;
		cout<<ans<<endl;	
	}
	return 0;
}
