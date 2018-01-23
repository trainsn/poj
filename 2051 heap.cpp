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
struct node 
{
	int time,period,id;
};

struct cmp
{
	bool operator()(node a,node b)
	{
		if (a.time==b.time)
			return a.id>b.id;
		else return a.time>b.time;
	}
};

priority_queue<node,vector<node>,cmp> minheap;

int main()
{
	//freopen("in","r",stdin);
   	//freopen("out","w",stdout);
	string cmd;
	int id,period,time,count;
	while (1)
	{
		cin>>cmd;
		if  (cmd.compare("#")==0)
			break;
		cin>>id>>period;
		node r;
		r.id=id;
		r.period=period;
		r.time=period;
		minheap.push(r);
	}
	cin>>count;
	while (count--)
	{
		
		node reg=minheap.top();
		cout<<reg.id<<endl;
		reg.time+=reg.period;
		minheap.pop();
		minheap.push(reg);
	}
	return 0;
}
