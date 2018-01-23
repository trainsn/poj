#include<stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	//freopen("1028.in", "r", stdin);
	//freopen("1028.out", "w", stdout);
	string s[105],c;
	int t,tmax;
	s[0]="Ignored";
	s[1]="http://www.acm.org/";
	tmax=1;t=1;
	while (1)
	{
		cin>>c;
		if (c=="QUIT") break;	
		if (c=="VISIT") 
		{
			tmax=t;
			cin>>s[++tmax];
			cout<<s[tmax]<<endl;
			t=tmax;
		}
		if (c=="BACK")
		{
			if (t==1) cout<<s[0]<<endl;
			else cout<<s[--t]<<endl;
		}
		if (c=="FORWARD")
		{
			if (t==tmax) cout<<s[0]<<endl;
			else cout<<s[++t]<<endl;
		}
	}
	return 0;
}
