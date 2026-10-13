#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main(void){
    setlocale(LC_ALL,"");

    wchar_t str1[10];
    wchar_t str2[20];
    wchar_t str3[30];

    wscanf(L"%ls",str1);
    wscanf(L"%ls",str2);
    wscanf(L"%ls",str3);

    wprintf(L"%-15ls|%20ls|%.5ls\n",str1,str2,str3);



    return 0;
}