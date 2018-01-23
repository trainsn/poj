#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<set>
#include<queue>
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
#define LL long long
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
struct node
{
	int x,y,time,pos;
};
int map[110][110],vis[110][110][4];
char c;
int sx,sy,ex,ey,n,m,sdir;

int getDir(char str[]) {
    if (!strcmp(str, "north"))
        return 0;
    if (!strcmp(str, "east"))
        return 1;
    if (!strcmp(str, "south"))
        return 2;
    return 3;
}

bool check(int x,int y)
{
	if (x<1||x>=n||y<1||y>=m)
		return 0;
	if (map[x][y]||map[x+1][y]||map[x][y+1]||map[x+1][y+1])
		return 0;
	return 1;
}
int bfs()
{
	queue<node> q;
	node a;
	a.x=sx,a.y=sy,a.pos=sdir,a.time=0;
	q.push(a);
	vis[sx][sy][sdir]=1;
	while (!q.empty())
	{
		node cur=q.front();
		q.pop();
		if (cur.x==ex&&cur.y==ey)
			return cur.time;
		int nx=cur.x;
		int ny=cur.y;
		for (int i=1;i<4;i++)
		{
			nx+=dx[cur.pos];
			ny+=dy[cur.pos];
			if (!check(nx,ny))
				break;
			if (!vis[nx][ny][cur.pos])
			{
				vis[nx][ny][cur.pos]=1;
				node cnt;
				cnt.x=nx,cnt.y=ny;
				cnt.pos=cur.pos,cnt.time=cur.time+1;
				q.push(cnt);
			}
		}
		for (int i=0;i<4;i++)
		{
			if (max(cur.pos,i)-min(cur.pos,i)==2)
				continue;
			if (vis[cur.x][cur.y][i])
				continue;
			vis[cur.x][cur.y][i]=1;
			node cnt=cur;
			cnt.pos=i;
			cnt.time=cur.time+1;
			q.push(cnt);
		}						
	}
	return -1;
}
int main()
{
	freopen("in","r",stdin);
   	freopen("out","w",stdout);
	while (1)
	{
		scanf("%d %d",&n,&m);
		if (!(n+m)) break;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				cin>>map[i][j];
		memset(vis,0,sizeof(vis));
		cin>>sx>>sy>>ex>>ey;
		char dir[20];
        scanf("%s", dir);
        sdir = getDir(dir);
		
		if (sx==ex &&sy==ey)
		{
			cout<<0<<endl;
			continue;
		}
		if (!check(ex,ey))
		{
			cout<<-1<<endl;
			continue;
		}
		int ans=bfs();
		if (ans!=-1)
			cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
