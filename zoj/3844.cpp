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

const int inf=0x3f3f3f3f;
const int maxn=12;
const int mod=1000001;
struct Node
{
	int a[maxn];
};
vector<Node> vc[mod+10];
int num[maxn];
int n;
int main()
{
	//freopen("in","r",stdin);
   	//freopen("out","w",stdout);
	int test;
   	cin>>test;
	while (test--)
	{
		for (int i=0;i<=mod;i++)
			vc[i].clear();
		cin>>n;
		Node tp;
		int sum=0;
		for (int i=0;i<n;i++)
		{
			cin>>num[i];
			sum+=num[i];
		}
		tp.a[n]=sum;
		sort(num,num+n);
		if (num[0]==num[n-1])
		{
			cout<<num[0]<<endl;
			continue;
		}
		for (int i=0;i<n;i++)
			tp.a[i]=num[i];
		vc[(tp.a[n]+mod)%mod].push_back(tp);//vc是一个容器
		int ans=inf;
		while (1)
		{
			//进行判断
			int cha=num[n-1]-num[0];
			sum=sum-num[n-1]-num[0]+2*cha;
			num[0]=cha,num[n-1]=cha;
			sort(num,num+n);
			if (num[0]==num[n-1])
			{
				ans=num[0];
				break;
			}
			tp.a[n]=sum;
			for (int i=0;i<n;i++)
				tp.a[i]=num[i];
			//在容器中寻找状态
			bool ok=0;
			int idx=(tp.a[n]+mod)%mod;
			for (int i=0;i<vc[idx].size();i++)
			{
				int j;
				for (j=0;j<n;j++)
				{
					if (tp.a[j]!=vc[idx][i].a[j])//vc[idx]类似于一个栈
						break;
				}
				if(j==n)
				{
					ok=1;//找到了
					break;
				}
			}
			if (ok==1)//若找到了，那么准备输出
				break;
			vc[idx].push_back(tp);
		}
		if (ans!=inf)
			cout<<ans<<endl;
		else 
			cout<<"Nooooooo!"<<endl;
	}
	return 0;
}
