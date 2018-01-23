#include<iostream>
#include<algorithm>
#include<cstring>
#include<functional>                           //greater<int> 所用。 
using namespace std;
int l[68],n,num,aim;
bool t[68];                                    //标记对应木棍是否已经使用。 
bool dfs(int stick,int len,int pos)
{
	/*stick表示当前已组合好的棍子数，len表示已有的长度，pos表示搜索到第几根。*/ 
	bool sign=(len==0?true:false);
	if(stick==num)                             //stick==num表示搜索成功。 
		return true;
	for(int i=pos+1;i<n;++i)
	{
		if(t[i])                               //该木棍已被用过，跳过。 
			continue;
		if(len+l[i]==aim)                      //len加上这个木棍刚好组成目标长度. 
		{
			t[i]=true;                         //先标记使用,再向下一层搜索。 
			if((dfs(stick+1,0,-1)))            //下一层搜索成功，返回成功。 
				return true;
			t[i]=false;                        //下一层搜索未成功，该木棒重新标记为未使用。 
			return false;                      //返回此层搜索失败。 
		}
		else if(len+l[i]<aim)                  //len加上此木棍组成小于目标长度的木棍。 
		{
			t[i]=true;                         //先标记使用。 
			if(dfs(stick,len+l[i],i))          //向下一层搜索,注意参数变化。 
				return true;
			t[i]=false;                        //下一层搜索失败，该木棍重现标记为未使用。 
			if(sign)
				return false;
			while(l[i]==l[i+1])                //下一根木棍和当前木棍长度相同,则不必重复检验，剪枝。 
				++i;
		}
	}
	return false;
}
int main()
{
	int i,sum;
	while(cin>>n&&n)
	{
		sum=0;
		for(i=0;i<n;++i)
		{
			cin>>l[i];
			sum+=l[i];
		}
		sort(l,l+n,greater<int>());                //将所有木棍降序排列。 
		for(aim=l[0];aim<=sum;++aim)
			if(sum%aim==0)
			{
				num=sum/aim;                     //num指拼成的木棍的个数。 
				memset(t,0,sizeof(t));
				if(dfs(1,0,-1))
				{
					cout<<aim<<endl;
					break;
				}
			}
	}
	return 0;
}