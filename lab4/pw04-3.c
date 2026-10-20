#include <stdio.h>
//15 Данные КБ→МБ a[i] = a[i-1] * 1024 1

int main(void){
    int n,i=1;
    unsigned long long a =1;

    scanf("%d",&n);

    while (i<=n){
    
    printf("%llu ", a);
    a=a*1024;
    i++;
    }
    printf("\n");

    return 0;
}