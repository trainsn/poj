#include<iostream>
using namespace std;

long long int t,p;
long long int euclid(long long int a,long long int b)
{
	if (b==0)
		return a;
	return euclid(b,a%b);
}
void exeuclid(long long a,long long b)
{
	if (b==0)
	{
		t=1;
		p=0;
		return;
	}
	long long int temp;
	exeuclid(b,a%b);
	temp=t;
	t=p;
	p=temp-(a/b)*p;
	return;
}
int main()
{
	//freopen("1061.in","r",stdin);
   	//freopen("1061.out","w",stdout);
	long long int x,y,m,n,l;
	long long int a,b,c,c1,gcd;
	while(scanf("%lld %lld %lld %lld %lld",&x,&y,&m,&n,&l)!=EOF)
	{
		a=n-m;
		b=l;
		c=x-y;
		gcd=euclid(a,b);
		c1=c%gcd;
		if (c1)
		{
			puts("Impossible");
			continue;
		}
		c/=gcd;
		a/=gcd;
		b/=gcd;
		exeuclid(a,b);
		t*=c;
		p*=c;
		t=(t%b+b)%b;
        printf("%lld\n",t);	
	}	
	return 0;
}
