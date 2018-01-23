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
#include<functional> 
using namespace std;

int l[68],n,num,aim;
bool t[68];  
bool dfs(int stick,int len,int pos)
{
	bool sign=(len==0?true:false);
	int i; 
	if (stick==num) 
		return true;
	for (i=pos+1;i<n;++i)
	{
		if (t[i]) continue;
		if (len+l[i]==aim)
		{
			t[i]=true;
			if (dfs(stick+1,0,-1))
				return true;
			t[i]=false;
			return false;
		}
		else if (len+l[i]<aim)
		{
			t[i]=true;
			if (dfs(stick,len+l[i],i))
				return true;
			t[i]=false;
			if (sign)
				return false;
			while (l[i]==l[i+1])
				++i;
		}	
	}
	return false;
}
int main()
{
	freopen("1011.in","r",stdin);
   	freopen("1011.out","w",stdout);
	int i,sum;
    //scanf("%d",&n);
	while (cin>>n&&n)
	{
		sum=0;
		for (i=0;i<n;++i)
		{
			cin>>l[i];
			sum+=l[i];
		}
		sort(l,l+n,greater<int>());
		for (aim=l[0];aim<=sum;++aim)
			if (sum%aim==0)
			{
				num=sum/aim;
				memset(t,0,sizeof(t));
				if (dfs(1,0,-1))
				{
					cout<<aim<<endl;
					break;
				}	
			}
		//scanf("%d",&n);
	}
	return 0;
}
