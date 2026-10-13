#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL,"");

    wchar_t mas[10];

    wscanf(L"%ls",mas);
    wprintf(L"Агент %ls авторизован в системе\n",mas);

    return 0;
}