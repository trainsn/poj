# include<stdio.h>
#include <stdlib.h>

int main()
{
    //freopen("1004.in","r",stdin);
   	//freopen("1004.out","w",stdout);
    /*double a[12];int i;
    for(i=0;i<12;i++)
                    scanf("%f",&a[i]);
    double t=0.0;
    for (i=0;i<12;i++)
    {
        t+=a[i];
    } 
    printf("$.2%f\n",t/12);
    system("pause");  //¼ÓÉÏsystem
    return 0;*/
    int i;
	float av, a, sum = 0.0;
	for (i = 1; i <= 12; i++ )
	{
		scanf("%f", &a );
		sum = sum + a;
	}
	av = sum / 12;
	printf("$%.2f", av );
	return 0;
}
