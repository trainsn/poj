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
int n,m;
char top_out[26];
int po=0;

struct degree
{
	int in;
	char to[26];
	int pt;
};

int top_sort(degree alph[],bool mark[],int num)
{
	memset(top_out,'\0',sizeof(top_out));
	po=0;
	
	int del_n=0;
	int zero=0;
	for (int i='A';i<'A'+n;i++)
	{
		if (mark[i] && !alph[i].in)
			zero++;
	}
	bool flag=false;
	while (zero)
	{
		if (zero>1)
			flag=true;
		for (int k='A';k<='A'+n;k++)
			if (mark[k] && !alph[k].in)
			{
				mark[k]=false;
				del_n++;
				top_out[po++]=k;
				for (int i=0;i<alph[k].pt;i++)
					alph[alph[k].to[i]].in--;
				break;
			}
			
		zero=0;
		for (int j='A';j<='A'+n;j++)
			if (mark[j] && !alph[j].in)
				zero++;
	}
	if (flag &&del_n==num)
			return 3;
	if (del_n<num)
		return 2;
	if (!flag && del_n==num && del_n<n)
		return 3;
	if (!flag && del_n==n)
		return 1;
}
int main()
{
	//freopen("in","r",stdin);
   	//freopen("out","w",stdout);
	int num;
	bool mark['Z'+1],mark_t['Z'+1];
	degree alph['Z'+1],alph_t['Z'+1];
	
	while (1)
	{
		cin>>n>>m;
		if (!n||!m)
			break;
		
		memset(mark,0,sizeof(mark));
		memset(mark_t,0,sizeof(mark_t));
		num=0;
		
		for (int k='A';k<'A'+n;k++)
		{
			alph[k].in=alph_t[k].in=0;
			alph[k].pt=alph_t[k].pt=0;
			memset(alph[k].to,'\0',sizeof(alph[k].to));
			memset(alph_t[k].to,'\0',sizeof(alph_t[k].to));				
		}
		
		char x,symbol,y;
		bool flag=false;
		bool sign=false;
		int value;
		int step;
		for (int pair=1;pair<=m;pair++)
		{
			cin>>x>>symbol>>y;
			if (x>='A'+n||y>='A'+n)
				sign=true;
			
			if (!mark[x]&&x<'A'+n)
				num++;
			if (!mark[y]&&y<'A'+n)
				num++;
			
			if (!flag&&!sign)
			{
				value=0;
				
				mark[x]=mark[y]=true;
				mark_t[x]=mark_t[y]=true;
				
				alph[y].in++;
				alph_t[y].in++;
				
				alph[x].to[alph[x].pt++]=y;
				alph_t[x].to[alph_t[x].pt++]=y;
				
				value=top_sort(alph_t,mark_t,num);
				
				if (value==1)
				{
					step=pair;
					flag=true;
				}
				else if (value==2)
				{
					step=pair;
					flag=true;
				}
				else if (value==3 && pair<m)
					for (int k='A';k<'A'+n;k++)
					{
						mark_t[k]=mark[k];
						alph_t[k].in=alph[k].in;
					}
					
				if (pair==m &&value==0)
					value=3;
			}
			
			if (sign && !flag &&num==n)
			{
				step=pair;
				value=2;
			}
			else if (sign && !flag &&pair==m &&num<n)
				value=3;
		}
		if (value==1)
		{
			cout<<"Sorted sequence determined after "<<step<<" relations: ";
			for (int i=0;i<po;i++)
				cout<<top_out[i];
			cout<<"."<<endl;
		}
		else if(value==2)
			cout<<"Inconsistency found after "<<step<<" relations."<<endl;
		else if (value==3)
			cout <<"Sorted sequence cannot be determined."<<endl;  
	}
	return 0;
}