#include <stdio.h>

//2 Время мин час мин 60

#define minhour 60

int main(void){

    int min;

    while (scanf("%d", &min) == 1 && min > 0){
        printf("%d hour %d min\n", min/minhour,min%minhour);
        
    }

    return 0;
}