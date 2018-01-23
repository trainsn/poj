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
	//freopen("1068.in","r",stdin);
   	//freopen("1068.out","w",stdout);
	int test,p[25],w[25],t,c,n,i,j,tmax;
	bool mo[55];
	scanf("%d",&test);
	for (int c=0;c<test;c++)
	{
		memset(mo,0,sizeof(mo));//true zuo false you
		memset(w,0,sizeof(w));
		t=0; 
		cin>>n;
		for (i=0;i<n;i++)
			cin>>p[i];
		for (i=0;i<n;i++)
		{
			if (i==0)
				for (int j=0;j<p[i];j++)
					mo[t++]=true;
			else 
				for (int j=0;j<p[i]-p[i-1];j++)
					mo[t++]=true;
			t++;
		}
		
		int d=0;
		for (i=1;i<2*n;i++)
		{
			if (!mo[i])
			{
				t=1; tmax=1;
				for (j=i-1;j>=0;j--)
				{
					if (!mo[j]) 
					{
						t++;
						tmax++;
					}
					else t--;
					if (t==0) break;	
				}	
				w[d++]=tmax;	
			}					
		}
		for (i=0;i<n-1;i++)
			cout<<w[i]<<" ";
		cout<<w[n-1]<<endl;
	}
	return 0;
}
