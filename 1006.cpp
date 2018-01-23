#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
	//freopen("1006.in","r",stdin);
   	//freopen("1006.out","w",stdout);
	int p=0,e=0,i=0,d=0,num=0,j,k;
	int f[40000];
	while (true) 
	{
		num++;
		scanf("%d %d %d %d",&p,&e,&i,&d);
		if ((p==-1)&&(e==-1)&&(i==-1)&&(d==-1)) break;
		memset(f,0,sizeof(f));
		p%=23;e%=28;i%=33;
		//p+=23;e+=28;i+=33;
		for (;p<=31253;p+=23)
			if (p!=0) f[p]++;
		for (;e<=31253;e+=28)
			if (e!=0) f[e]++;
		for (;i<=31253;i+=33)
			if (i!=0) f[i]++;
		for (j=0;j<=31253;j++)
		{
			if (f[j]==3) 
			{
               k=j-d;
               while (k<=0) k+=21252;
               printf("Case %d: the next triple peak occurs in %d days.\n",num,k);
			   break;
             }
		}
		
	}
	return 0;
}
