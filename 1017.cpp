#include<iostream>
using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}

int main(void)
{
	int s1,s2,s3,s4,s5,s6;      //6种size的盒子数量
	while(cin>>s1>>s2>>s3>>s4>>s5>>s6 && (s1+s2+s3+s4+s5+s6))
	{
		int BoxNum=0;           //放进所有盒子所需的最少箱子数

		BoxNum+=s6;             //6*6的盒子，每个都刚好独占一个箱子

		BoxNum+=s5;             //5*5的盒子，放进箱子后，每个箱子余下的空间只能放11个1*1的盒子
		s1=max(0,s1-s5*11);     //把1*1的盒子尽可能地放进已放有一个5*5盒子的箱子

		BoxNum+=s4;             //4*4的盒子，放进箱子后，每个箱子余下的空间为5个2*2的盒子空间
		                        //先把所有2*2的盒子尽可能地放进这些空间
		if(s2>=s4*5)             //若2*2的盒子数比空间多
			s2-=s4*5;           //则消去已放进空间的部分
		else                    //若2*2的盒子数比空间少
		{                       //则先把所有2*2的盒子放进这些空间
			s1=max(0,s1-4*(s4*5-s2));   //再用1*1的盒子填充本应放2*2盒子的空间
			s2=0;               //一个2*2空间可放4个1*1盒子
		}

		BoxNum+=(s3+3)/4;       //每4个3*3的盒子完全独占一个箱子
		s3%=4;            //3*3的盒子不足4个时，都放入一个箱子，剩余空间先放2*2，再放1*1
		if(s3)
		{                       //当箱子放了i个3*3盒子，剩下的空间最多放j个2*2盒子
			if(s2>=7-2*s3)       //其中i={1,2,3} ; j={5,3,1}  由此可得到条件的关系式
			{
				s2-=7-2*s3;
				s1=max(0,s1-(8-s3));  //当箱子放了i个3*3盒子，并尽可能多地放了个2*2盒子后
			}                         //剩下的空间最多放j个1*1盒子，其中i={1,2,3} ; j={7,6,5}
			else                //但当2*2的盒子数不足时，尽可能把1*1盒子放入剩余空间
			{  //一个箱子最多放36个1*1，一个3*3盒子空间最多放9个1*1，一个2*2盒子空间最多放4个1*1
				s1=max(0,s1-(36-9*s3-4*s2));    //由此很容易推出剩余空间能放多少个1*1
				s2=0;
			}
		}

		BoxNum+=(s2+8)/9;       //每9个2*2的盒子完全独占一个箱子
		s2%=9;            //2*2的盒子不足9个时，都放入一个箱子，剩余空间全放1*1
		if(s2)
			s1=max(0,s1-(36-4*s2));

		BoxNum+=(s1+35)/36;     //每36个1*1的盒子完全独占一个箱子

		cout<<BoxNum<<endl;
	}
	return 0;
}