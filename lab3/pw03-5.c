#include <stdio.h>

int main(void){

    char a;

    scanf("%c",&a);

    printf("CODE_DEC: %d\n", a);
    printf("CODE_HEX: %x\n", a);
    printf("CODE_OCT: %o\n", a);
    printf("UPPER: %c\n", a -'a'+'A');
    printf("NEXT: %c\n", a + 1);
    printf("PREV: %c\n", a - 1);

    return 0;
}