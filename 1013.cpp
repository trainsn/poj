#include<stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("1013.in","r",stdin);
   	//freopen("1013.out","w",stdout);
	int cases,c,i,j;
	string left[3],right[3],status[3];
	int time['L'+1];
	bool zero['L'+1];
	scanf("%d",&cases);
	for (c=0;c<cases;c++)
	{
		memset(zero,0,sizeof(zero));
		memset(time,0,sizeof(time));
		for (i=0;i<3;i++)	
			cin>>left[i]>>right[i]>>status[i];
		for (i=0;i<3;i++)
		{
			switch(status[i][0])
			{
				case 'u'://zuo zhong you qing 
				{
					for (j=0;j<left[i].length();j++)
					{
						time[left[i][j]]++;
						time[right[i][j]]--;
					}
					break;
				}
				case 'd':
				{
					for (j=0;j<left[i].length();j++)
					{
						time[left[i][j]]--;
						time[right[i][j]]++;
					}
					break;
				}
				case 'e':
				{
					for (j=0;j<left[i].length();j++)
					{
						zero[left[i][j]]=true;
						zero[right[i][j]]=true;
					}
					break;
				}
			}
			
		}
		int max=-1;
			char v;
			for (i='A';i<='L';i++)
			{
				if (zero[i])
					continue;
				if (abs(time[i])>max)
				{
					max=abs(time[i]);
					v=i;
				}
			}
			cout<<v<<" is the counterfeit coin and it is ";
			if (time[v]<0) 
				cout<<"light."<<endl;
			else 
				cout<<"heavy."<<endl;
		
	}
	return 0;
}
