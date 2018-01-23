#include<stdio.h>
#include<memory.h>
int maxDay[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int isWin[102][13][32];
int judge(int y,int m,int d){
    int win;
    if(y>101 || (y==101 && (m>11 || m==11 && d>4)))
        return 1;
    if(y==101 && m==11 && d==4)
        return 0;
    if(isWin[y][m][d]==-1){
        win=0;
        if(m!=12){
            if(d<=maxDay[m+1] || (d==29 && m==1 && (y%4==0) && y!=0))
                if(judge(y,m+1,d)==0)
                    win=1;
        }else if(judge(y+1,1,d)==0)
                    win=1;
        if(win==0){
            if(d<maxDay[m])
                win=1-judge(y,m,d+1);
            else if(m!=12)
                win=1-judge(y,m+1,1);
            else
                win=1-judge(y+1,1,1);
        }
        isWin[y][m][d]=win;
    }
    return isWin[y][m][d];
}
int main(){
    int iCase;
    int m,d,y;
    memset(isWin,-1,sizeof(isWin));     //进行初始化
    scanf("%d",&iCase);
    while(iCase--){
        scanf("%d%d%d",&y,&m,&d);
        if(judge(y-1900,m,d)==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}