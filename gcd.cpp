# include<stdio.h>
#include <stdlib.h>  //添加上stdlib.h
main()
{
      int m,n,t,r;
      scanf("%d,%d",&m,&n);
      if(m<n)
      {
             t=m;
             m=n;
             n=t;
             r=m%n;
      }
      while(r!=0)
      {
                 m=n;
                 n=r;
                 r=m%n;
      }
      printf("%d\n",n); 
      system("pause");  //加上system
}
