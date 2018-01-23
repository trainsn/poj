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
char outhash[20][9] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", 
"muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
int n,i,inday,inyear,outyear,inmon,num;
string sinmon;
char doc;
int main()
{
	//freopen("1008.in","r",stdin);
   	//freopen("1008.out","w",stdout);
	scanf("%d",&n);
	printf("%d\n",n);
	for (i=0;i<n;i++)
	{
		//scanf("%d.%s %d",&inday,&sinmon,&inyear);
		//pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu.
		cin>>inday>>doc>>sinmon>>inyear;
		if (sinmon=="pop") inmon=1;
		if (sinmon=="no") inmon=2;
		if (sinmon=="zip") inmon=3;
		if (sinmon=="zotz") inmon=4;
		if (sinmon=="tzec") inmon=5;
		if (sinmon=="xul") inmon=6;
		if (sinmon=="yoxkin") inmon=7;
		if (sinmon=="mol") inmon=8;
		if (sinmon=="chen") inmon=9;
		if (sinmon=="yax") inmon=10;
		if (sinmon=="zac") inmon=11;
		if (sinmon=="ceh") inmon=12;
		if (sinmon=="mac") inmon=13;
		if (sinmon=="kankin") inmon=14;
		if (sinmon=="muan") inmon=15;
		if (sinmon=="pax") inmon=16;
		if (sinmon=="koyab") inmon=17;
		if (sinmon=="cumhu") inmon=18;
		if (sinmon=="uayet") inmon=19;
		num=inyear*365+(inmon-1)*20+inday;
		outyear=num/260;
		num%=260;
		printf("%d %s %d\n",num%13+1,outhash[num%20],outyear);
	}
	
	
	return 0;
}
