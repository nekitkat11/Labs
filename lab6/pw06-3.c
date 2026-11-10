#include <stdio.h>

//6 Числа в диапазоне от 10 до 50 / Числа вне этого диапазона

int main(void){
    int number;
    int countin=0;
    int countout=0;
    long long sumin=0;
    long long sumout=0;

    while(scanf("%d",&number) == 1 && number != 0){
        if (number >=10 && number <=50){
            countin++;
            sumin+=number;
        }
        else{
            countout++;
            sumout+=number;
        }
        
    }
    printf("кол-во в диапазоне: %d\n", countin);
    printf("среднее: %.2f\n", (double)sumin/countin);

    printf("кол-во вне диапазона: %d\n", countout);
    printf("среднее: %.2f\n", (double)sumout/countout);

    return 0;
}