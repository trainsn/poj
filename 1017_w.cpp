#include<cstdio>
using namespace std;

const int f[4]={0,7,3,1};
int main()
{
	freopen("1017.in","r",stdin);
   	freopen("1017.out","w",stdout);
   	int v[7],ans,rest,sum; 
	
	while (1)
	{
		rest=0;
		scanf("%d %d %d %d %d %d",&v[1],&v[2],&v[3],&v[4],&v[5],&v[6]);
		sum=0;
		for (int i=1;i<=6;i++)
			sum+=v[i];
		if (!sum) break;
		ans=v[6];
		if (v[1]-v[5]*11>0)
		{
			v[1]-=v[5]*11;
			ans+=v[5];
			v[5]=0;
		}	
		else 
		{
			v[1]=0;
			ans+=v[5];
			v[5]=0;
		}
		if (v[2]-v[4]*5>0)
		{
			v[2]-=v[4]*5;
			ans+=v[4];
			v[4]=0;	
		}
		else 
		{		
			rest=(v[4]*5-v[2])*4;
			ans+=v[4];
			v[4]=0;
			v[2]=0;
		}
		if (v[1]>rest)
		{
			v[1]-=rest;
			rest=0;
		}	
		else 
		{
			v[1]=0;
			rest-=v[1];
		}
				
		ans+=v[3]/4;
		v[3]%=4;
		if (v[3]) 		
		{
			ans++;
			rest=36-v[3]*9;
		}
		if (v[2]>f[v[3]])
		{
			v[2]-=f[v[3]];
			rest-=f[v[3]]*4;
		}
		else 
		{
			rest-=v[2]*4;
			v[2]=0;		
		}
		if (v[1]>rest)
		{
			v[1]-=rest;
			rest=0;
		}
		else 
		{
			v[1]=0;
			rest-=v[1];
		}
		if (v[2]>0)
		{
			ans+=(v[2]-1)/9+1;
			v[2]%=9;
			rest=36-v[2]*4;
		}
		if (v[1]>rest)
			v[1]-=rest;
		else 
			v[1]=0;
		if (v[1]>0) ans+=(v[1]-1)/36+1;
		printf("%d\n",ans);			
	}
	return 0;
}
