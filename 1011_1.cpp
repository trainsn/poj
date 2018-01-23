#include<iostream>
#include<algorithm>
#include<cstring>
#include<functional>                           //greater<int> ���á� 
using namespace std;
int l[68],n,num,aim;
bool t[68];                                    //��Ƕ�Ӧľ���Ƿ��Ѿ�ʹ�á� 
bool dfs(int stick,int len,int pos)
{
	/*stick��ʾ��ǰ����ϺõĹ�������len��ʾ���еĳ��ȣ�pos��ʾ�������ڼ�����*/ 
	bool sign=(len==0?true:false);
	if(stick==num)                             //stick==num��ʾ�����ɹ��� 
		return true;
	for(int i=pos+1;i<n;++i)
	{
		if(t[i])                               //��ľ���ѱ��ù��������� 
			continue;
		if(len+l[i]==aim)                      //len�������ľ���պ����Ŀ�곤��. 
		{
			t[i]=true;                         //�ȱ��ʹ��,������һ�������� 
			if((dfs(stick+1,0,-1)))            //��һ�������ɹ������سɹ��� 
				return true;
			t[i]=false;                        //��һ������δ�ɹ�����ľ�����±��Ϊδʹ�á� 
			return false;                      //���ش˲�����ʧ�ܡ� 
		}
		else if(len+l[i]<aim)                  //len���ϴ�ľ�����С��Ŀ�곤�ȵ�ľ���� 
		{
			t[i]=true;                         //�ȱ��ʹ�á� 
			if(dfs(stick,len+l[i],i))          //����һ������,ע������仯�� 
				return true;
			t[i]=false;                        //��һ������ʧ�ܣ���ľ�����ֱ��Ϊδʹ�á� 
			if(sign)
				return false;
			while(l[i]==l[i+1])                //��һ��ľ���͵�ǰľ��������ͬ,�򲻱��ظ����飬��֦�� 
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
		sort(l,l+n,greater<int>());                //������ľ���������С� 
		for(aim=l[0];aim<=sum;++aim)
			if(sum%aim==0)
			{
				num=sum/aim;                     //numָƴ�ɵ�ľ���ĸ����� 
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