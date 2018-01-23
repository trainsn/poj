#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 110;
 
struct node {
    int x,y;
    int time,pos;
};
int n,m,sx,sy,sdir,ex,ey,map[MAXN][MAXN];
int vis[MAXN][MAXN][4];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1}; 
 
int getDir(char str[]) {
    if (!strcmp(str, "north"))
        return 0;
    if (!strcmp(str, "east"))
        return 1;
    if (!strcmp(str, "south"))
        return 2;
    return 3;
}
 
int check(int x, int y) {
    if (x < 1 || x >=n || y < 1 || y >= m)
        return 0;
    if (map[x][y] || map[x+1][y] || map[x][y+1] || map[x+1][y+1])
        return 0;
    return 1;
}
 
int bfs() {
    queue<node> q;
    node a;
    a.x = sx, a.y = sy, a.pos = sdir, a.time = 0;
    q.push(a);
    vis[sx][sy][sdir] = 1;
    while (!q.empty()) {
        node cur = q.front();
        q.pop();
        if (cur.x == ex && cur.y == ey) 
            return cur.time;
        int nx = cur.x;
        int ny = cur.y;
        for (int i = 1; i < 4; i++) {
            nx += dx[cur.pos];
            ny += dy[cur.pos];
            if (!check(nx, ny))
                break;
            if (!vis[nx][ny][cur.pos]) {
                vis[nx][ny][cur.pos] = 1;
                node cnt;
                cnt.x = nx, cnt.y = ny;
                cnt.pos = cur.pos, cnt.time = cur.time+1;
                q.push(cnt);
            }
        }
        for (int i = 0; i < 4; i++) {
            if (max(cur.pos, i)-min(cur.pos, i) == 2)
                continue;
            if (vis[cur.x][cur.y][i])
                continue;
            vis[cur.x][cur.y][i] = 1;
            node cnt = cur;
            cnt.pos = i;
            cnt.time = cur.time+1;
            q.push(cnt);
        }
    }
    return -1;
}
 
int main() {
	freopen("in","r",stdin);
   	freopen("out","w",stdout);
    while (scanf("%d%d", &n, &m) != EOF && n+m) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &map[i][j]);
        memset(vis, 0, sizeof(vis));
        scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
        char dir[20];
        scanf("%s", dir);
        sdir = getDir(dir);
        if (sx == ex && sy == ey) {
            printf("0\n");
            continue;
        }
        if (!check(ex, ey)) {
            printf("-1\n");
            continue;
        }
        int ans = bfs();
        if (ans != -1)
            printf("%d\n", ans);
        else printf("-1\n");
    }
    return 0;
}
