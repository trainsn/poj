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
struct f{
	int num;
	char w[50];
}s[101];
bool cmp(struct f a,struct f b)
{
	return a.num<b.num;
}
int main(){
	freopen("1007.in","r",stdin);
   	freopen("1007.out","w",stdout);
	int i,len,n,j,k;
	scanf("%d %d",&len,&n);
	for (i=0;i<n;i++)
	{
		s[i].num=0;
		scanf("%s",&s[i].w);
		for (j=1;j<len;j++)
			for (k=0;k<j;k++)
				if (s[i].w[j]<s[i].w[k])	
					s[i].num++;
	}
	sort(s,s+n,cmp);
	for (i=0;i<n;i++)
		printf("%s\n",s[i].w);
	return 0;
}
