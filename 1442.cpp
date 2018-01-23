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

int array[30005];
priority_queue<int,vector<int>,less<int> >maxheap;
priority_queue<int,vector<int>,greater<int> > minheap;

int main()
{
	freopen("in","r",stdin);
   	freopen("out","w",stdout);
	int n,m,i,op,k,t1,t2;
	//while (scanf("%d%d",&n,&m) && n)
	{
		scanf("%d%d",&n,&m);
		for (i=0;i<n;i++)
			scanf("%d",&array[i]);
		
		k=0;
		for (i=0;i<m;i++)
		{
			scanf("%d",&op);
			while (k<op)
			{
				minheap.push(array[k]);
				if (!maxheap.empty()&&maxheap.top()>minheap.top())
				{
					t1=minheap.top();minheap.pop();
					t2=maxheap.top();maxheap.pop();
					maxheap.push(t1);
					minheap.push(t2);
				}
				k++;
			}
			printf("%d\n",minheap.top());
			maxheap.push(minheap.top());
			minheap.pop();
		}
	}
	return 0;
}
