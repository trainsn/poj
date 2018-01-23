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
int maxday[13]={0,31,28,31,30,31,30,31,31,30,31,30,31}; 
int iswin[102][13][32];
int solve(int y,int m,int d)
{
	int win;
	if (y>101 || (y==101&&(m>11 ||(m==11&&d>4))))
		return 1;
	if (y==101 && m==11 && d==4)
		return 0;
	if (iswin[y][m][d]==-1)
	{
		win=0;
		if (m!=12)
		{
			if (d<=maxday[m+1] || (y%4==0 && y!=0 && m==1 &&d==29 ))
				if (solve(y,m+1,d)==0)
					win=1;
		}
		else 
			if (solve(y+1,1,d)==0)
				win=1;
		if (win==0)
		{
			if (d<maxday[m])
				win=1-solve(y,m,d+1);
			else if (m!=12)
				win=1-solve(y,m+1,1);
			else 
				win=1-solve(y+1,1,1);
		}
		iswin[y][m][d]=win;	
	}
	return iswin[y][m][d];
}
int main()
{
	freopen("in","r",stdin);
   	freopen("out","w",stdout);
   	memset(iswin,-1,sizeof(iswin));
	int test,y,m,d;
	scanf("%d",&test);
	for (int i=0;i<test;i++)
	{
		cin>>y>>m>>d;
		if (solve(y-1900,m,d)==1)
		{
			cout<<"YES"<<endl;
		}
		else 
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
