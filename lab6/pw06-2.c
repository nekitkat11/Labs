#include <stdio.h>
#include <wchar.h>
#include <locale.h>

//30 Количество символов, чей Unicode-код является полным квадратом

int square(unsigned int value){
    unsigned int k = 0;
    while(k*k<value){
        k++;
    }
    return k*k==value;
}

int main(void){
    setlocale(LC_ALL,"");
    wint_t ch;
    int count =0;

    while((ch=getwchar()) != L'#' && ch != WEOF){
        if (square(ch)){
            count++;
        }
    
    }
    wprintf(L"кол-во: %d\n",count);
    return 0;
}