#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float x,y;
} punct;


int main()
{
    punct pct[3];
    int i;
    float ab,bc,ac,perimetru,arie;
    for(i = 0;i<3;i++){
        printf("pct[%d] = ",i);
        scanf("%f %f",&pct[i].x,&pct[i].y);
    }
    //debug
    for(i = 0;i<3;i++){
        printf("pct[%d] (%f ; %f)\n",i,pct[i].x,pct[i].y);
    }
    //distante
    ab = sqrt(pow(pct[1].x-pct[0].x,2)+pow(pct[1].y-pct[0].y,2));
    bc = sqrt(pow(pct[2].x-pct[1].x,2)+pow(pct[2].y-pct[1].y,2));
    ac = sqrt(pow(pct[2].x-pct[0].x,2)+pow(pct[2].y-pct[0].y,2));
    //debug
    printf("ab = %f \nbc = %f \nac = %f\n",ab,bc,ac);

    if((ab+ac>bc)&&(ab+bc>ac)&&(bc+ac>ab)){
        printf("Punctele formeaza un triunghi");
        perimetru = ab+ac+bc;
        arie = sqrt((perimetru/2)*(((perimetru/2)-ab)*((perimetru/2)-ac)*((perimetru/2)-bc)));
        printf("\nPerimetru = %f\nArie = %f",perimetru,arie);
    }else printf("Punctele nu formeaza triunghi");


    return 0;
}
