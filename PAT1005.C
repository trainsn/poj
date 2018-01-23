#include <stdio.h>
int main(void){
    freopen("out.txt","w",stdout);
    int a;
    char b;
    float c;
    scanf("%d,%c%f",&a,&b,&c);
    printf("%f",c);
}

