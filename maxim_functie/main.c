#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float interval[2];
float coef[4];

float val(float x){
    float eval = 0;
    eval = coef[0]*pow(x,2)+coef[1]*x+coef[2]-coef[3];
    return eval;
}

 void afis(float x, float y){
    printf("maximul pe interval este f(%2.2f) = %2.2f",x,y);
 }
void maxim(){
    float xmax,ymax;
    xmax = -coef[1]/(2*coef[0]);
    ymax = val(xmax);

    // daca a mai mare ca 0
    if(coef[0]>0){
        printf("Functia nu are maxim.\n");
        if(val(interval[0]) > val(interval[1]))
            afis(interval[0],val(interval[0]));
        else
            afis(interval[1],val(interval[1]));
    } else {
        if((ymax >= interval[0]) && (ymax <=interval[1])){
            afis(xmax,ymax);
        }
        else {
            printf("maximul functiei nu este in interval\n");
            if(val(interval[0]) > val(interval[1]))
                afis(interval[0],val(interval[0]));
            else
                afis(interval[1],val(interval[1]));
        }
    }
}

int main()
{
    printf("Introduceti capetele intervalului: ");
    scanf("%f %f",&interval[0],&interval[1]);
    printf("introduceti coeficientii ecuatiei: \na*x^2 + b*x + c = d\n sub forma a b c d: ");
    scanf("%f %f %f %f",&coef[0],&coef[1],&coef[2],&coef[3]);
    printf("%2.2f*x^2+%2.2f*x+%2.2f = 0\n\n",coef[0],coef[1],coef[2]-coef[3]);
    maxim();
    return 0;
}
