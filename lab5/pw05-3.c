#include <stdio.h>
#include <math.h>

//14 1 / 2i SUM: 0.968750

int main(void){
    int n,i;
    double SUM;

    while(scanf("%d",&n)==1 && n > 0){
        SUM=0;

        for(int i=1;i<=n;i++){

            SUM+= 1/pow(2,i);

        }       
        printf("SUM: %.6lf\n",SUM);





    }
    
    
    
    
    return 0;
}