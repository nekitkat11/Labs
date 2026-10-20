#include <stdio.h>

//25 byte_to_kb kb = byte / 1024

double byte_to_kb(double byte){
    return byte / 1024;
}
int main(void){
    double byte;
    
    while (scanf("%lf",&byte)==1){
        printf("%.2f KB\n", byte_to_kb(byte));
    }
    



    return 0;
}