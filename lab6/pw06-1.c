#include <stdio.h>
#include <ctype.h>

//2 Количество гласных, согласных и остальных символов (латиница)

int main(void)
{
    int ch;
    int glas = 0;
    int sogl = 0;
    int other = 0;


    while ((ch = getchar()) != '#' && ch != EOF) {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            {

            int lower = tolower(ch);

            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u'){
                
                glas++;
            } 
            else {
                sogl++;
            }
        } 
        else {
            other++;
        }
    }

    printf("Гласные: %d\n", glas);
    printf("Согласные: %d\n", sogl);
    printf("Остальные: %d\n", other);

    return 0;
}