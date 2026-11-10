#include <stdio.h>
#include <math.h>

//6 Разность модулей

int main(void){
    double a,b;

    while (scanf("%lf %lf", &a, &b)==2){
            double result = fabs(a) - fabs(b);
            printf("Разность модулей: %.4f\n", result);

    }
    return 0;
}