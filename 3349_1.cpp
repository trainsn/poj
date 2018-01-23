#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int K = 14997;

struct Node
{
    int floor[7];
};
int m[15000];
Node snow[15000][100];
bool solve(Node x,Node y)  //比较
{
    sort(x.floor,x.floor+6);
    sort(y.floor,y.floor+6);
    for(int i=0;i<6;i++)
    {
        if(x.floor[i]!=y.floor[i])
            return false;
    }
    return true;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(m,0,sizeof(m));
        int ok=0;
        for(int i=0; i<n; i++)
        {
            int sum=0;
            Node pp;
            for(int j=0; j<6; j++)
            {
                scanf("%d",&pp.floor[j]);
                sum=(sum+pp.floor[j])%14997;
            }
            if(ok==0)
            {
                for(int j=0; j<m[sum]; j++) //按键值查找
                {
                    if(solve(pp,snow[sum][j]))
					{
                        ok=1;break;
                    }
                }
                snow[sum][m[sum]]=pp;
                m[sum]++;
            }
        }
        if(ok)
            printf("Twin snowflakes found.\n");
        else
            printf("No two snowflakes are alike.\n");
    }
    return 0;
}