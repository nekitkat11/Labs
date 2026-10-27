#include <stdio.h>

//24 (a3 - b3) / (a2 - b2) Центр масс (упрощ.) 4.6667

double calc(double a,double b){
    return ((a * a * a)-(b * b * b)) / ((a * a)-(b * b));
}


int main(void){
    double a,b;

    while(scanf("%lf %lf", &a,&b)==2){
        printf("%.4f\n", calc(a,b));
    }
    return 0;
}