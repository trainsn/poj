#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
#define LL long long

int main()
{
	freopen("in","r",stdin);
   	freopen("out","w",stdout);
	int n;
	float x1,x2,x3,x4,y1,y2,y3,y4;
	cin>>n;
	cout<<"INTERSECTING LINES OUTPUT"<<endl;
	while (n--)
	{
		scanf("%f %f %f %f %f %f %f %f",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		float cha1=(x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
	    float cha2=(x2-x1)*(y4-y1)-(x4-x1)*(y2-y1);
		if (cha1==0&&cha2==0)
		{
			cout<<"LINE"<<endl;
			continue;
		}
		cha1=(x2-x1)*(y4-y3)-(x4-x3)*(y2-y1);
		if (cha1==0)
		{
			cout<<"NONE"<<endl;
			continue;
		}
		float a1=y1-y2,b1=x2-x1,c1=x2*y1-x1*y2;
		float a2=y3-y4,b2=x4-x3,c2=x4*y3-x3*y4;
		float ansx=(c1*b2-c2*b1)/(a1*b2-a2*b1);
		float ansy=(a1*c2-c1*a2)/(a1*b2-a2*b1);
		printf("POINT %.2f %.2f\n",ansx,ansy);	
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}
