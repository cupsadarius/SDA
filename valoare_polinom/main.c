#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* in fisierul de intrare avem

gradul_polinomului x0 // pe prima linie
a0 a1 a2 a... an //coeficientii incepand cu termenul liber si terminand cu coeficientul lui x^n

*/

int main()
{
    FILE *f;
    float *coef,x,pol_val = 0;
    int n,i;
    if(!(f = fopen("in.txt","r"))){
        printf("Nu pot accesa fisierul de intrare.");
    } else {
        fscanf(f,"%d %f",&n,&x);
        printf("gradul este: %d deci avem %d coeficienti.\ncalculam valoarea in %f",n,n+1,x);
        if(!(coef = (float *)malloc(n*sizeof(float)))){
            printf("Nu pot aloca memorie pt vector de coeficienti!");
        }else{
            printf("\nCoeficienti: ");
            for(i=0;i<=n;i++){
                fscanf(f,"%f ",(coef+i));
                printf("%f ",coef[i]);
                pol_val = pol_val + coef[i]*pow(x,i);
            }
            printf("\nValoarea polinomului in punctul x=%f este: %f",x,pol_val);
        }
    }
    fclose(f);
    return 0;
}
