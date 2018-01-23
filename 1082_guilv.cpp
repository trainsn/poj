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
   	int tt,y,m,d; 
	cin>>tt;
	for (int i=0;i<tt;i++)
	{
		cin>>y>>m>>d;
		if ((m+d)%2==0) 
		{
			cout<<"YES"<<endl;
			continue;
		}
		if ((m==9||m==11)&&d==30)
		{
			cout<<"YES"<<endl;
			continue;
		}
		cout<<"NO"<<endl;	
	}
	return 0;
}
