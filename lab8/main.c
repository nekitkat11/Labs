#include <stdio.h>
#include "myarrfunc.h"

#define maxs 1000

int main(void){
    int k;
    int n = 0;
    int arr[maxs];
    int index[maxs];
    int filled = 0;
    int result,count;
    char command;

    
    while(1){
        printf("\n========== МЕНЮ ==========\n");
        printf("a.Задать размер массива\n");
        printf("b.Заполнить массив\n");
        printf("c.Представление массива(значения,адреса)\n");
        printf("d.Поиск значения последнего положительного элемента массива\n");
        printf("e.Определение количества элементов массива по значению ниже введенного k\n");
        printf("f.Определение индексов элементов массива по значению выше введенного k\n");
        printf("g.Выход\n");

        printf("Выберите пункт: ");
        scanf(" %c",&command);

        switch(command){

            case 'a':
                printf("Введите размер массива: ");
                if (scanf("%d",&n)!=1){
                    printf("Ошибка ввода\n");
                    return 0;
                }
                if (n<1 || n > maxs){
                    printf("Неверный размер\n");
                    return 0;
                }
                else{
                    filled = 0;
                    printf("размер массива задан\n");
                }
                break;

            case 'b':
                if (n == 0){
                    printf("Сначала задайте размер\n");
                    break;
                }

                printf("Введите элементы массива: \n");
                
                for (int i = 0; i<n;i++){
                    printf("arr[%d] = ", i);

                    if (scanf("%d", &arr[i]) != 1){
                        printf("Ошибка ввода\n");
                        return 0;
                    }
                }
                filled = 1;
                printf("Массив заполнен\n");
                break;

            case 'c':
                if(filled==0){
                    printf("Сначала задайте размер и заполните массив\n");
                    break;
                }

                for (int i = 0; i<n;i++){
                    printf("Index: %d, Value: %d, Adress: %p\n",i,arr[i],(void *)(arr+i));
                }
                break;

            case 'd':
                if(filled==0){
                    printf("Сначала задайте размер и заполните массив\n");
                    break;
                }

                result = last_positive(arr,n);

                if (result == -1){
                    printf("Положительных элементов нет\n");
                }
                else{
                    printf("Положительных элемент: %d\n", result);
                }
                break;
            
            case 'e':
                if(filled==0){
                    printf("Сначала задайте размер и заполните массив\n");
                    break;
                }

                printf("Введите k: ");
                
                if(scanf("%d",&k) !=1){
                    printf("Ошибка ввода\n");
                    return 0;
                }
                count = count_below(arr,n,k);

                printf("Количество элементов меньше %d: %d\n", k, count);
                break;
            
            case 'f':
                if(filled==0){
                    printf("Сначала задайте размер и заполните массив\n");
                    break;
                }

                printf("Введите k: ");

                if (scanf("%d",&k)!=1){
                    printf("Ошибка ввода\n");
                    return 0;
                }

                count = index_up(arr,n,k,index);

                if (count == 0){
                    printf("Таких элементов нет\n");
                }
                else{
                    printf("Индексы элементов больше %d:\n", k);

                    for (int i = 0; i<count;i++){
                        printf("%d\n",index[i]);
                    }
                }
                break;

            case 'g':
                printf("Программа завершена\n");
                return 0;

            default:
                printf("Неверный пункт меню\n");
        }
    }

    return 0;
}