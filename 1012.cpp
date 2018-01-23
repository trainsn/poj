#include <stdio.h>

int main()
{
    int people[50] = {0}, k, Joseph[14] = {0};//Joseph用于打表，不然超时
    while(scanf("%d", &k) != EOF && k != 0)
    {
        if (Joseph[k] != 0)
        {
            printf("%d\n", Joseph[k]);
            continue;
        }
        int n = 2 * k;
        int m = 1;
        people[0] = 0;//people[0] = 0表示编号从0开始
        for (int i = 1; i <= k; i++)
        {
            //每次枚举完毕将剩下的人按从0到n - i编号，只要好人没有杀掉，则前面k - 1个编号是不变的
            people[i] = (people[i - 1] + m - 1) % (n - i + 1);
            if (people[i] < k)//第k个人的编号为k - 1,所以这里是<而不是<=
            {
                i = 0 ;
                m++;
            }
        }
        Joseph[k] = m;
        printf("%d\n", m);
    }
    return 0;
}
