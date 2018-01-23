#include <cstdio>
#include <algorithm>
#include <math.h>  
using namespace std;

int main()
{
	//freopen("1005.in","r",stdin);
   	//freopen("1005.out","w",stdout);
   	const float pi=3.1415926;
	int n;
	float x,y,r,year;
	
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%f %f",&x,&y);
		r=x*x+y*y;
		year=pi*r/100.0+1;
		printf("Property %d: This property will begin eroding in year %d.\n",i,int(year));
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
