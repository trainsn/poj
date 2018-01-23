#include <iostream>
#include <algorithm>
using namespace std;
 
struct f{
    int num;
    char w[50];
}s[101];
bool cmp(struct f a, struct f b){
    return a.num < b.num;
}
int main(){
    int i, len, n, j, k;
    cin>>len>>n;
    for(i = 0; i < n; i++){
        s[i].num = 0;
        cin>>s[i].w;
        for(j = 1; j < len; j++)
            for(k = 0; k < j; k++)
                if(s[i].w[j] < s[i].w[k])//ÇóÄæÐòÊý
                    s[i].num++;
    }
    sort(s, s+n, cmp);
    for(i = 0; i < n; i++)
        cout<<s[i].w<<endl;
    return 0;
}