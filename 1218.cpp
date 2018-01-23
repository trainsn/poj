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
	int test,n,ans,i,t;
	bool mo[105]; 
	scanf("%d",&test);
	while (test--)
	{
		scanf("%d",&n);
		ans=0;
		memset(mo,1,sizeof(mo));
		for (t=2;t<=n;t++)
		{
			for (i=1;i*t<=n;i++)
				if (mo[i*t]) mo[i*t]=false;
				else mo[i*t]=true;
		}
		for (i=1;i<=n;i++)
			if (mo[i]) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
