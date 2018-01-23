#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int  N= 110;
int a[N][N],sum[N];
int main()
{
    //freopen("1002.txt","r",stdin);
    int n,i,j,k,sum1,max,ans;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        ans=-99999;
        for(i=1;i<=n;i++)
        {
            memset(sum,0,sizeof(sum));
            for(j=i;j<=n;j++)//将二维压缩成一维的
            {
                for(k=1;k<=n;k++)
                {
                    sum[k]+=a[j][k];
                }
                max=-99999;
                sum1=0;
                for(k=1;k<=n;k++)//求最大值
                {
                    if(sum1>0)
                    {
                        sum1+=sum[k];
                    }
                    else
                    {
                        sum1=sum[k];
                    }
                    if(max<sum1)
                    {
                        max=sum1;
                    }
                }
                if(ans<max)
                {
                    ans=max;
                }
            }
        }
        printf("%d\n",ans);
    }
}