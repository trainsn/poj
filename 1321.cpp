#include<stdio.h>
#define MAX 9
int hashrow[MAX];
int hashcol[MAX];
char map[MAX][MAX];
int n,k,count;
void DFS(int pre)
{
	int i,j;
	if(k==0)
	{
		count++;
		return;
	}
	for(i=pre+1;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(map[i][j]=='#' && hashrow[i]==0 && hashcol[j]==0)
			{
				hashrow[i]=hashcol[j]=1;
				k--;
				DFS(i);
				k++;
				hashrow[i]=hashcol[j]=0;
			}
		}
	}
}
int main(void)
{
	int i;
	while(scanf("%d%d",&n,&k) && n!=-1)
	{
		count=0;
		for(i=0;i<n;i++) scanf("%s",map[i]);
		DFS(-1);
		printf("%d\n",count);
	}
	return 0;
}