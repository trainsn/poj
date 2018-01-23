#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int dp[110000],t[30000],s[2000][2];
int main()
{
    int cash,n;
    while(scanf("%d%d",&cash,&n)>0)
    {
         int cnt=0;
         //memset(t,0,sizeof(t));
         for(int i=1;i<=n;i++)
         {
                 scanf("%d%d",&s[i][0],&s[i][1]);
                 int k=1;
                 if(s[i][0]==0||s[i][1]==0)
                 continue;
                 while(s[i][0]-k>0)
                 {
                        t[cnt++]=k*s[i][1];
                        s[i][0]-=k;
                        k*=2;
                 }
                 t[cnt++]=s[i][0]*s[i][1];
         }
         memset(dp,0,sizeof(dp));
         for(int i=0;i<cnt;i++)
         {
                 for(int j=cash;j>=t[i];j--)
                 if(dp[j]<dp[j-t[i]]+t[i])
                 dp[j]=dp[j-t[i]]+t[i];
         }
         printf("%d\n",dp[cash]);
    }
    return 0;
}