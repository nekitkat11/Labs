#include <stdio.h>

//12 Присвоить первой переменной произведение, второй - частное

void change(double *a, double *b){
    double origa = *a;
    double origb =*b;

    *a = origa * origb;
    if (origb!=0){
        *b =origa/origb;
    }
    else{
        printf("error\n");
        *b==0;
    }
}


int main(void){
    double a,b;
    if (scanf("%lf %lf",&a, &b)!= 2){
        printf("error\n");
        return 0;
    }
    printf("До вызова:\n");
    printf("a = %.4f\n", a);
    printf("b = %.4f\n",b);

    change(&a,&b);

    printf("После вызова:\n");
    printf("a = %.4f\n", a);
    printf("b = %.4f\n",b);

    return 0;
    }