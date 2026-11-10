#include <stdio.h>

//16 Число Перрина
// P(0) = 3, P(1) = 0, P(2) = 2
// P(n) = P(n - 2) + P(n - 3) для n >= 3

long long perrinrec(int n){
    if (n == 0) return 3;
    if (n == 1) return 0;
    if (n == 2) return 2;
    return perrinrec(n-2) + perrinrec(n-3);
}

long long perriniter(int n){
    if (n == 0) return 3;
    if (n == 1) return 0;
    if (n == 2) return 2;
    long long p0 =3;
    long long p1=0;
    long long p2=2;
    long long pn = 0;

    for (int i=3;i<=n;i++){
        pn=p0+p1;
        p0=p1;
        p1=p2;
        p2=pn;   
    }
    return pn;
}


int main(void){
    int n;

    printf("Введите число Перрина:\n");
    if(scanf("%d", &n)!=1 || n<0){
        printf("error\n");
        return 0;
    }

    long long rec=perrinrec(n);
    long long iter=perriniter(n);

    printf("Результат рекурсивно: %lld\n", rec);
    printf("Результат итеративно: %lld\n", iter);

    return 0;
}

