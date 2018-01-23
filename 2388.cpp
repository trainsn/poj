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

long n,i,a[10005];
int main()
{
	freopen("2388.in","r",stdin);
   	freopen("2388.out","w",stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++)
			scanf("%d",&a[i]);
	sort(a,a+n);
	printf("%d\n",a[n/2]);
	return 0;
}
