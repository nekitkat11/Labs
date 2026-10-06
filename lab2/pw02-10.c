#include <stdio.h>
#include <stdint.h>

int main(void){

    int packet_id;
    float voltage;

    uint8_t status_code;
    uint16_t checksum;

    scanf("%x %o %f", &packet_id, &status_code, &voltage);


    checksum = packet_id + status_code;

    printf("PACKET_ID: %d\n", packet_id);
    printf("STATUS_CODE: %u\n", status_code);
    printf("STATUS_CHAR: %c\n", status_code);
    printf("VOLTAGE: %.2f\n", voltage);
    printf("CHEKSUM: %u\n", checksum);

    return 0;

}