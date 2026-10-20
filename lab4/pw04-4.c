#include <stdio.h>

//21 Сумма нечетных S = 1 + 3 + 5 + ... + (2N-1)

int main(void){
    int n,i=1;
    long long sum = 0;
    scanf("%d", &n);

    while(i<=n){
        sum += 2 * i - 1;
        i++;

    }

    printf("Sum = %lld\n",sum);

    return 0;
}