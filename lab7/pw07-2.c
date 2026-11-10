#include <stdio.h>

//30 Количество символов, чей ASCII-код кратен 11

int main(void){
    int ch;
    int total=0;
    int kratno=0;

    while((ch=getchar())!=EOF){
        total++;

        if (ch % 11==0){
            kratno++;
        }
    }

    printf("Всего символов: %d\n",total);
    printf("Кратно 11: %d\n", kratno);

    return 0;
}

