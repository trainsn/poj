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
const int MAXN=362881;
struct Node
{
	int s[9];
	int pre;
	int dir;
}que[MAXN];
bool hash[MAXN];
int path[MAXN];

int fac[]={1,1,2,6,24,120,720,5040,40320,362880};
int cantor(int *s)
{
	int sum=0;
	for (int i=0;i<9;i++)
	{
		int num=0;
		for (int j=i+1;j<9;j++)
		{
			if (s[i]>s[j]) num++;
		}
		sum+=num*fac[9-i-1]; 
	}
	return sum;
}
int move[4][2]={{-1,0},{1,0},{0,-1},{0,1}};//u,d,l,r
void output(int len)
{
	for (int i=len-1;i>=0;i--)
	{
		if (path[i]==0) printf("u");
		else if (path[i]==1) printf("d");
		else if (path[i]==2) printf("l");
		else if (path[i]==3) printf("r");
	}
	printf("\n");
}

void bfs()
{
	int front=-1,rear=0;
	que[0].pre=-1;
	que[0].dir=-1;
	memset(hash,false,sizeof(hash));
	hash[cantor(que[0].s)]=true;
	if (cantor(que[0].s)==0)
	{
		output(0);
		return;
	}
	while (front<rear)
	{
		front++;
		int tmp;
		for (tmp=0;tmp<9;tmp++)
			if (que[front].s[tmp]==9)
				break;
		int x=tmp/3;
		int y=tmp%3;
		for (int i=0;i<4;i++)
		{
			int tx=x+move[i][0];
			int ty=y+move[i][1];
			if (tx<0||tx>2||ty<0||ty>2)continue;
			que[rear+1]=que[front];
			que[rear+1].pre=front;
			que[rear+1].dir=i;
			que[rear+1].s[tmp]=que[rear+1].s[tx*3+ty];
			que[rear+1].s[tx*3+ty]=9;
			int now=cantor(que[rear+1].s);
			if (now==0)
			{
				int len=0;
				int t=rear+1;
				while (que[t].pre!=-1)
				{
					path[len++]=que[t].dir;
					t=que[t].pre;
				}
				output(len);
				return;
			}
			if (!hash[now])
			{
				rear++;
				hash[now]=true;
			}
		}
	}
}
int main()
{
	//freopen("in","r",stdin);
   	//freopen("out","w",stdout);
	char str[10];
	while (scanf("%s",&str)!=EOF)
	{
		if (str[0]=='x') que[0].s[0]=9;
		else que[0].s[0]=str[0]-'0';
		for (int i=1;i<9;i++)
		{
			scanf("%s",&str);
			if (str[0]=='x') que[0].s[i]=9;
			else que[0].s[i]=str[0]-'0';
		}
		bfs();
	}
	return 0;
}
