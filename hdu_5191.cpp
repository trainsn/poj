#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL __int64
using namespace std;

LL height[150005];
LL in[150005];
LL out[150005];

LL mint(LL a,LL b){
    if(a<b) return a;
    return b;
}
LL maxt(LL a,LL b){
    if(a>b) return a;
    return b;
}

int main(){
		freopen("in","r",stdin);
   	freopen("out","w",stdout);
    LL n,w,h;
    while(scanf("%I64d%I64d%I64d",&n,&w,&h)!=EOF){
        LL sum=0;
        memset(height,0,sizeof(height));
        for(LL i=w+1;i<=n+w;i++)
		{
            scanf("%I64d",&height[i]);
            sum+=height[i];
        }
        if(sum<w*h) puts("-1");
        else
		{
            n=n+w+w;
            in[0]=out[0]=0;
            LL ans=(1ll<<62);
			printf("%I64d\n",ans);
            for(LL i=1;i<=n;i++){
                if(height[i]>=h)
				{
                    out[i]=out[i-1]+height[i]-h;
                    in[i]=in[i-1];
                }
                if(height[i]<=h)
				{
					in[i]=in[i-1]+h-height[i];
					out[i]=out[i-1];
                }
                if(i-w>=0)
				{
                    ans=mint(ans,maxt(in[i]-in[i-w],out[i]-out[i-w]));
                }
            }
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
