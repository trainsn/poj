#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char a[5001];
short dp[5001][5001];     //dp[i][j] means a[i~j] become return string needs to insert or delete's min operate number
int min1(int b,int c,int d){
    int temp=b<c?b:c;
    temp=temp<d?temp:d;
    return temp;
}  
int min2(int e,int f){
    int temp=e<f?e:f;
    return temp;
}   
int main()
{
    freopen("1159.in","r",stdin);
   	freopen("1159.out","w",stdout);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
            scanf("%s",a+1);     //cin a string
            int len=strlen(a+1);
            for(int i=0;i<=len;i++)
            {
                    dp[i][i]=0;
            }
            for(int j=1;j<=len-1;j++)
            
                    for(int k=1;k<=len-j;k++)
                    {
                            int g=k+j;
                            if(a[g]==a[k]){
                                 dp[k][g]=min1(dp[k+1][g-1],dp[k+1][g]+1,dp[k][g-1]+1);
                                 }
                            else{
                                 dp[k][g]=min2(dp[k][g-1]+1,dp[k+1][g]+1);
                                 }
                    }
                                 
            printf("%d\n",dp[1][len]);
    }
    return 0;
}
