#include <stdio.h>
#include <stdint.h>

int main(void){
    int n;
    uint8_t x;

    scanf("%d", &n);

    x = n+10;
    printf("ADD: %u\n", x);

    x=n*2;
    printf("MUL2: %u\n", x);

    x=n*n;
    printf("SQR: %u\n", x);





    return 0;
}