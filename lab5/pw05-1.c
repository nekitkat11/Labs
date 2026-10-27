#include <stdio.h>

//2 Кубическая зависимость: X3 1.0 4.0 0.5

int main(void){

    double x;
    int i = 1;

    printf("N\tX\tY\n");

    for(x=1.0;x<=4.0;x+=0.5){

        printf("%d\t%.4f\t%.4f\n", i, x, x * x * x * x);
        i++;
    }


    return 0;
}