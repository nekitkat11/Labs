#include <stdio.h>
#include <ctype.h>

//2 Выводить только заглавные буквы, остальные игнорировать

int main(void){
    int ch;

    while((ch = getchar()) != EOF){
        if (isupper(ch)){
            putchar(ch);
        }
    }
    putchar('\n');

    return 0;
}
