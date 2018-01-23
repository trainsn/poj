#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1e5+10;

int a[maxn];

int gcd(int a,int b)
{
    if(b) return gcd(b,a%b);
    return a;
}

int main()
{
    freopen("in","r",stdin);
   	freopen("out","w",stdout);
	int cas=1,n;
    while(~scanf("%d",&n)){
        int mmin = 1999999999,num=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(a[i]<mmin) mmin = a[i];
        }
        int tmp=a[0];
        for(int i=1;i<n;i++)
            tmp=gcd(tmp,a[i]);
        printf("Case %d: ",cas++);
        if(tmp!=1){
            puts("-1");
            puts("");
            continue;
        }
        else{
            printf("%d\n",2*n-2);
            for(int i=1;i<n;i++)
                printf("1 %d\n",i+1);
            for(int i=1;i<n;i++)
                printf("1 %d\n",i+1);
            puts("");
        }
    }
    return 0;
}