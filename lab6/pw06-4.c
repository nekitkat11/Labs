#include <stdio.h>

//12 Объем продаж Бонус 2% до 20000, 3% от 20000 до 100000, 5% свыше

int main(void){
    double sale;
    double rate;
    double bonus;

    printf("Объём:");
    if (scanf("%lf",&sale)!=1 || sale <0){
        printf("error\n");
        return 0;
    }
    if (sale <= 20000){
        rate =2;
    }
    else if (sale >=20000 && sale <=100000){
        rate=3;
    }
    else{
        rate=5;
    }

    bonus = (sale*rate)/100;

    printf("Объём продаж: %2.f\n",sale);
    printf("Процент бонуса: %.0f\n",rate);
    printf("Итоговый бонус: %2.f%%\n",bonus);


    return 0;
}