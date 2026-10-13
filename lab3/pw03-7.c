#include <stdio.h>
#include <string.h>

#define Linux "LinuxDistro"

int main(void){
    const char a[]="2026";

    printf("Distro: %s\n", Linux);
    printf("RDATE: %s\n", a);
    printf("STRLEN: %zu\n",strlen(Linux));
    printf("SIZEOF: %zu\n", sizeof(Linux));



    return 0;
}