#include<iostream>
using namespace std;
void mult(char a[],char b[],char s[])
{
	int i,j,k=0,alen,blen,sum=0,res[200][200]={0};
    char result[200];
	alen=strlen(a);blen=strlen(b);
	for (i=0;i<alen;i++)
		for (j=0;j<blen;j++)
			res[i][j]=(a[i]-'0')*(b[j]-'0');
	for (i=alen-1;i>=0;i--)
	{
		for(j=blen-1;j>=0;j--)	
			sum+=res[i+blen-1-j][j];
		result[k]=sum%10;
		k++;
		sum/=10;
	}		
	for (i=blen-2;i>=0;i--)
	{
		for(j=0;j<=i;j++)
			sum+=res[i-j][j];
		result[k]=sum%10;
		k++;
		sum/=10;
	}
	if (sum!=0)
	{
		result[k]=sum;
		k++;
	}		
	for (i=0;i<k;i++)
		result[i]+='0';
	for (i=0;i<k;i++)
		s[i]=result[k-1-i];
	s[k]='\0';
	while (1)
	{
		if (strlen(a)!=strlen(s)&&s[0]=='0')
			strcpy(s,s+1);
		else break;
	}
}
int main()
{
	freopen("1001.in","r",stdin);
   	freopen("1001.out","w",stdout);
	int i,pl,k,n,t,z,c,j;
	char r[6],rr[200],b[200],all[9];
	while (scanf("%s%d",all,&n)!=EOF)
	{
		k=0;
		memset(r,0,sizeof(r));
		memset(rr,0,sizeof(rr));
		memset(b,0,sizeof(b));
		for (i=0;i<=5;++i)
		{
			if ((all[i])=='.') pl=i;
			else r[k++]=all[i];
		}
		pl=strlen(r)-pl;
		strcpy(rr,r);
		for (i=2;i<=n;i++)
			mult(r,rr,rr);
		i=strlen(rr)-1;
		z=0;
		while ((rr[i]=='0')&&(i>strlen(rr)-pl*n))
		{
			z++;
			--i;
		}
		if (i==strlen(rr)-pl*n) z++;
		c=0;
		while (rr[c]=='0') c++;
		t=strlen(rr)-pl*n-c;
		if (t<0)
		{
			printf(".");
			for (j=1;j<=-t;++j) printf("0");
		}
		for (i=c;i<=strlen(rr)-1-z;++i)
		{
			if (i==t) printf(".");
			printf("%c",rr[i]);
		}
		printf("\n");
	}
	return 0;
}
