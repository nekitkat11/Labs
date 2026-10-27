#include <stdio.h>

//20 Простые числа (первые 8) Найти и вывести сумму

int main(void){
    double arr[8]={2,3,5,7,11,13,17,19};
    double sum;
    printf("Arr: ");
    for(int i=0; i<=8;i++){
        printf("%.2f ",arr[i]);
        sum += arr[i];

    }


    printf("\nSUM: %.2f\n",sum);
    return 0;

}