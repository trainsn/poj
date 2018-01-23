#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cctype>
using namespace std;
#define ll long long
const int mod=100000*10+1;
const int inf=0x3f3f3f3f;
const int maxn=12;
int num[maxn];
int n;
struct Node
{
    int a[maxn];
};
vector<Node>vc[mod+10];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<=mod;i++)
            vc[i].clear();
        Node tp;
        cin>>n;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>num[i];
            sum+=num[i];
        }
        tp.a[n]=sum;
        sort(num,num+n);
        if(num[0]==num[n-1])
        {
            cout<<num[0]<<endl;
            continue;
        }
        for(int i=0;i<n;i++)
            tp.a[i]=num[i];
        vc[(tp.a[n]+mod)%mod].push_back(tp);
        int ans=inf;
        while(1)
        {
            int cha=num[n-1]-num[0];
            sum=sum-num[n-1]-num[0]+2*cha;//新的sum
            num[0]=cha,num[n-1]=cha;
            sort(num,num+n);
            if(num[0]==num[n-1])
            {
                ans=num[0];
                break;
            }
            tp.a[n]=sum;
            for(int i=0;i<n;i++)
                tp.a[i]=num[i];
            bool ok=0;
            int idx=(tp.a[n]+mod)%mod;//去相应的索引中去找看是否有相同的状态
            for(int i=0;i<vc[idx].size();i++)
            {
                    int j;
                    for(j=0;j<n;j++)
                    {
                        if(tp.a[j]!=vc[idx][i].a[j])
                            break;
                    }
                    if(j==n)
                    {
                        ok=1;//找到了！
                        break;
                    }
            }
            if(ok==1)
                break;
            vc[idx].push_back(tp);
        }
        if(ans!=inf)
            cout<<ans<<endl;
        else
            cout<<"Nooooooo!"<<endl;
    }
    return 0;
}
