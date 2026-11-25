#include "myarrfunc.h"
#include <stddef.h>

//Функция1-6 
//Поиск значения последнего положительного элемента массива

int last_positive(int *arr, size_t n){

    int result = -1;

    for (int i =0; i < n; i++){

        if(*(arr+i)>0){
            result = *(arr+i);
        }
    }
    return result;
}

//Функция2-19
//Определение количества элементов массива по значению ниже введенного k
int count_below(int *arr, size_t n, int k){
    int count=0;
    for (int i =0;i<n;i++){
        if (*(arr+i)<k){
            count++;
        }
    }
    return count;
}

//Функция3-24
//Определение индексов элементов массива по значению выше введенного k
int index_up(int *arr, size_t n, int k, int *index){
    int count = 0;

    for (int i =0; i<n;i++){
        if(*(arr+i)>k){
            *(index + count)=i;
            count++;
        }
    }
    return count;
}






