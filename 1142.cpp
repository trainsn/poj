#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
#define LL long long

int sum(int n)
{
    int        ans = 0;

    while (n > 0)
    {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

bool work(int n)
{
    int        i, temp, ans1, ans2;

    ans1 = sum(n);
    temp = n;
    i = 2;
    ans2 = 0;
    while (i <= sqrt(double(n)))
    {
        if (n % i == 0)
        {
            n /= i;
            ans2 += sum(i);
        }
        else
            i++;
    }
    ans2 += sum(n);
    if (ans1 == ans2 && temp != n)
        return true;
    else
        return false;
}

int main()
{
	//freopen("in","r",stdin);
   	//freopen("out","w",stdout);
    int        n;
    while (cin >> n && n != 0)
    {
        n++;
        while (!work(n))
            n++;
        cout << n << endl;
    }
    return 0;
}
