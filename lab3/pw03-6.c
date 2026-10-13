#include <stdio.h>

int main(void){
    char a[100];
    int width;
    scanf("%s %d",a, &width);

    printf("%*s\n", width,a);
    printf("%-*s\n", width+5,a);


    return 0;
}