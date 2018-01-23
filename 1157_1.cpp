#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int dp[105][105];
int val[105][105];

int main()
{
    freopen("in","r",stdin);
   	freopen("out","w",stdout);
	int m, n;
    scanf("%d%d", &m, &n);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &val[i][j]);
        }
    }
    dp[1][1] = val[1][1];
    for (int i = 2; i <= m; i++)
    {
        dp[1][i] = max(dp[1][i], val[1][i]);
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1] + val[i][j]);
        }
    }
    printf("%d\n", dp[m][n]);
    return 0;
}
