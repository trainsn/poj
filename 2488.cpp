#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 30;
bool vis[maxn][maxn], flag;
int dx[] = { -1, 1, -2, 2, -2, 2, -1, 1 },
		dy[] = { -2, -2, -1, -1, 1, 1, 2, 2 };//注意顺序
int n, m, end;
char s[60];

bool ok(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y, int cnt, char *s) {
	if (flag)
		return;
	if (cnt == end) {
		puts(s);
		flag = true;
		return;
	}
	for (int i = 0; i < 8; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (ok(xx, yy) && !vis[xx][yy]) {
			vis[xx][yy] = true;
			s[cnt] = yy + 'A';
			s[cnt+1] = xx + '1';
			dfs(xx, yy, cnt+2, s);
			vis[xx][yy] = false;
		}
	}
}

int main() {
	int t;
	int cas=0;
	scanf("%d", &t);
	while (t--) {
		printf("Scenario #%d:\n",++cas);
		scanf("%d%d", &n, &m);
		end = n * m * 2;
		flag = false;
		for (int j = 0; j < m; j++) {//先枚举列，以得到最小字典序
			for (int i = 0; i < n; i++) {
				memset(vis, 0, sizeof(vis));
				memset(s, 0, sizeof(s));
				s[0] = j + 'A';
				s[1] = i + '1';
				vis[i][j]=true;//记得标记。。
				dfs(i, j, 2, s);
				if (flag)
					goto endloop;
			}

		}
		endloop: if (!flag)
			puts("impossible");
		puts("");
	}
}
