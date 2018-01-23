/*
zoj_1037    最短路
暂且归类到最短路吧。。
刚看觉得好难，dijk或者bellman或者floyd或者kruskal都想了一下。怎么看都不简单。
后来队友说找下规律就好了。。仔细想了下，才发现是道很水的题。。

规律:偶数行或偶数列必定存在全部为1的路径把所有点连起来
     否则m行n列中存在 m*n-1个1 和 一个 sqrt(2) 的路径连起所有点
*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int T,row,col,count;
    scanf( "%d",&T );
    count=1;
    while( T-- )
    {
        scanf( "%d%d",&row,&col );
        printf( "Scenario #%d:\n",count );
        if( row%2==0 || col%2==0 )  printf( "%.2lf\n\n",double(row)*double(col) );
        else printf( "%.2lf\n\n",double(row)*double(col)-1.0+sqrt(2.0) );
        count++;
    }
}
