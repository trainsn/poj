#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <map>
#include <algorithm>
#include <list>
#include <ctime>
#include <set>
#include <string.h>
#include <queue>
#include <cstdio>
using namespace std;
typedef int typep;
int maxData = 500000;
#define N 505
#define CLR(arr, what) memset(arr, what, sizeof(arr))
int path[N][N];
int d[N];
int n;

int lvl, lvr;
int costc[N];
int costlv[N];

bool check(int lv) {
    return (lvl <= lv && lv <= lvr);
}

bool relax(typep u, typep& v, typep w, typep lv1, typep lv2) {
    if (v > (u + w) && check(lv1) && check(lv2)) {
        v = u + w;
        return true;
    } else
        return false;
}

int cnt[N]; //记录顶点入队列次数
bool final[N]; //记录顶点是否在队列中，SPFA算法可以入队列多次
bool SPFA(int s) {
    queue<int> myqueue;
    int i;
    CLR(final, 0);
    CLR(cnt, 0);
    final[s] = true;
    cnt[s]++; //源点的入队列次数增加
    myqueue.push(s);
    int topint;
    bool judge;
    while (!myqueue.empty()) {
        topint = myqueue.front();
        myqueue.pop();
        final[topint] = false;
        for (i = 0; i < n; ++i) {
            if (d[topint] < maxData) {
                judge = relax(d[topint], d[i], path[topint][i], costlv[topint], costlv[i]);
                if (judge) {
                    if (!final[i]) { //判断是否在当前的队列中
                        final[i] = true;
                        cnt[i]++;
                        if (cnt[i] >= n) //当一个点入队的次数>=n时就证明出现了负环。
                            return true;
                        myqueue.push(i);
                    }
                }
            }
        }
    }
    return false;
}


int main() {
    int degree, num, cp, cl, cx, rpob, rpmo;
    cin >> degree >> num;
    n = num;
    bool judge;
    CLR(path, maxData);
    for (int abc = 0; abc < num; abc++) {
        scanf("%d%d%d", &cp, &cl, &cx);
        costc[abc] = cp;
        costlv[abc] = cl;
        for (int i = 0; i < cx; i++) {
            scanf("%d%d", &rpob, &rpmo);
            rpob--;
            path[abc][rpob] = rpmo;
        }
    }
    int res = maxData;
    for (int i = costlv[0] - degree; i < costlv[0] + 1; i++) {
        lvl = i;
        lvr = i + degree;
        CLR(d, maxData);
        d[0] = 0;
        judge = SPFA(0);
        for (int i = 0; i < n; i++) {
            res = min(res, d[i] + costc[i]);
        }
    }
    cout << res;
    return 0;
}