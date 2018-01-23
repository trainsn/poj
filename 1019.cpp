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
unsigned a[32000],s[32000];
int i,test,pos,len,n;

int main()
{
	freopen("in","r",stdin);
   	freopen("out","w",stdout);
	a[1]=s[1]=1;
	for (i=2;i<=31269;i++)
	{
		a[i]=a[i-1]+(int)log10((double)i)+1;
		s[i]=s[i-1]+a[i];
	}
	
	scanf("%d",&test);
	while (test--)
	{
		scanf("%d",&n);
		i=1;
		while (s[i]<n)
			i++;
		
		pos=n-s[i-1];
		len=0;
		for (i=1;len<pos;i++)
		{
			len+=(int)log10((double)i)+1;
		}
		printf("%d\n",(i-1)/(int)pow((double)10,len-pos)%10);
	}
	return 0;
}
