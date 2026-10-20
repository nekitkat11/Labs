#include <stdio.h>
#include <stdint.h>

//9 uint16_t m, v (float)m * v * v / 2

int main(void){
    uint16_t m,v;
    float E;

    printf("m v:");
    scanf("%hu %hu",&m,&v);

    E=(float)m*v*v / 2;

    printf("E= %.2f\n", E);
    printf("uint16_t: %llu byte\n",sizeof(uint16_t));
    printf("float: %llu byte\n", sizeof(float));



    return 0;

}