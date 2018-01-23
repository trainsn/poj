# include<stdio.h>
#include <stdlib.h>
int main()
{
    //freopen("1003.in","r",stdin);
   	//freopen("1003.out","w",stdout);
	float a,sum=0.0;
	int count=2,flag=0;
	while (scanf("%f",&a),a!=0.0)
	{
          if (flag==1)         
             printf("\n");
          if (flag==0)
             flag=1;
          count=1;
          sum=0;
          while (sum+=(1.0/(count+1)))
          {
                if (sum<a)
                count++;
                else break;      
          }
          printf("%d card(s)",count);
    }    
    return 0;
	
}
/*#include <stdio.h>
int main()
{
        freopen("1003.in","r",stdin);
   	freopen("1003.out","w",stdout);
	float a,sum=0.0;
	int count=2,flag=0;
	while(scanf("%f",&a),a!=0.0)
    {
		if(flag==1)
		   printf("\n");
		if(flag==0)
		  flag=1;
		
		count=1;
		sum=0;
		while(sum+=(1.0/(count+1)))
		{
			if(sum<a)
		 count++;
		 else break;
		 
		 }
		 printf("%d card(s)",count);
		}
	return 0;
	}*/

