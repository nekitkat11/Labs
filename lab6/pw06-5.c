#include <stdio.h>
#include <math.h>

//16 Калькулятор степеней: квадрат числа, куб числа, корень квадратный, корень
//кубический, выход

int main(void){
    int choice;
    double x;

    while(1){
        printf("КАЛЬКУЛЯТОР СТЕПЕНЕЙ\n");
        printf("1.Квадрат числа\n");
        printf("2.Куб числа\n");
        printf("3.Корень квадратный\n");
        printf("4.Корень кубический\n");
        printf("5.Выход\n");

        if (scanf("%d",&choice)!=1){
            printf("error\n");
            return 0;
        }

        if (choice ==5){
            printf("Выход\n");
            break;
        }
        if (choice<1 || choice >5){
            printf("Некорректный пункт\n");
            continue;
        }
        printf("Введите число: ");
        if (scanf("%lf",&x)!=1){
            printf("error\n");
            return 0;
        }
        switch(choice){
            case 1:     
                printf("Квадрат числа: %.4f\n",x*x);
                break;
            case 2:
                printf("Куб числа: %.4f\n", x*x*x);
                break;
            case 3:
                if (x<0){
                    printf("Нельзя извлечь действительный корень\n");
                }
                else{
                    printf("Квадратный корень: %.4f\n",sqrt(x));
                    break;
                }
            case 4:
                printf("Кубический корень: %.4f\n",cbrt(x));
                break;
        }
    }
    return 0;
}