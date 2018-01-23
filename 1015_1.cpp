#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

struct Inf
{
    int p;  ///控方值
    int d;  ///辩方值
    int s;  ///控辩和
    int v;  ///控辩差
}pre[210];

int path[25][810];//记录所选定的候选人的编号  
int dp[25][810];//dp[j][k]：取j个候选人，使其辩控差为k的所有方案中，辩控和最大的方案的辩控和  

/*回溯，确认dp[j][k]方案是否曾选择过候选人i*/  
bool select(int j, int k, int i)
{
    while(j > 0 && path[j][k] != i)
    {
        k -= pre[path[j][k]].v;
        j--;
    }
    if(j == 0) return true;
    else return false;
}

int main()
{
    
	freopen("in","r",stdin);
   	freopen("out","w",stdout);
	int id[25];
    int i, j, k;
    int n, m;
    int T = 0;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        if(n == 0 && m == 0) break;
        memset(path, 0, sizeof(path));
        memset(pre, 0, sizeof(pre));
        memset(dp, -1, sizeof(dp));///一开始定义为-1..表示该方案不可行..以后状态转移找可行方案的时候用到..

        for(i = 1; i <= n; ++i){
            scanf("%d %d", &pre[i].p, &pre[i].d);
            pre[i].s = pre[i].p + pre[i].d;
            pre[i].v = pre[i].p - pre[i].d;
        }

        int fix = m*20;//总修正值，修正极限为从[-400,400]映射到[0,800]  
        dp[0][fix] = 0; //由于修正了数值，因此dp[0][fix]才是真正的dp[0][0]  

		/*DP*/  
        for(i = 1; i <= m; ++i)
        for(k = 0; k <= fix*2; ++k)
            if(dp[i-1][k] >= 0)
                for(j = 1; j <= n; ++j)
                if(dp[i-1][k] +  pre[j].s > dp[i][k+pre[j].v] && select(i-1, k, j)){///!!!!Important~ select d+p is max while the solution is d-p
                    dp[i][k+pre[j].v] = dp[i-1][k] + pre[j].s;
                    path[i][k+pre[j].v] = j;
                 }

        int k;
        for(k = 0; k <= fix; ++k){
            if(dp[m][fix-k] >= 0 || dp[m][fix+k] >= 0) ///promise the d-p is min
            ///!!!!//从中间向两边搜索最小辨控差的位置k  
            break;
        }

        int div = dp[m][fix-k] > dp[m][fix+k]?(fix-k):(fix+k);//最小辨控差  

		/*Output*/  
        int D = (dp[m][div] - div + fix)/2;   //辩方总值 = （辨控和+辨控差-修正值）/2  
        int P = (dp[m][div] + div - fix)/2;  //控方总值 = （辨控和-辨控差+修正值）/2  

        printf("Jury #%d\n", ++T);
        printf("Best jury has value %d for prosecution and value %d for defence:\n", P, D);

        for(i = 0, j = m, k = div; i < m; ++i){
            id[i] = path[j][k];
            k -= pre[id[i]].v;
            j--;
        }

        sort(id, id+m);

        for(i = 0; i < m; ++i)
        printf(" %d", id[i]);
        printf("\n\n");
    }

    return 0;
}
