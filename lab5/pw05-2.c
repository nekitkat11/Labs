#include <stdio.h>

//8 Сплошной прямоугольник 5x10 -

int main(void){
    const int HEIGHT = 5;
    const int WIDTH = 10;
    

    for(int a=0;a<HEIGHT;a++)
    {
        
        for(int b=0;b<WIDTH;b++)
        {

            printf("-");
        }
        printf("\n");
    }


    return 0;
}