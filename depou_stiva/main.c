#include <stdio.h>
#include <stdlib.h>

struct Tren
{
    int numar;
    struct Tren *urmator;
}*depou;

void eliminare_tren()
{
    struct Tren *temp, *var=depou;
    if(var==depou)
    {
        depou = depou->urmator;
        free(var);
    }
    else
    printf("\nDepou gol");
}

void introducere_tren(int numar)
{
    struct Tren *temp;
    temp=(struct Tren *)malloc(sizeof(struct Tren));
    temp->numar=numar;
    if (depou == NULL)
    {
         depou=temp;
         depou->urmator=NULL;
    }
    else
    {
        temp->urmator=depou;
        depou=temp;
    }
}

void afisare_depou()
{
     struct Tren *var=depou;
     if(var!=NULL)
     {
          printf("\nLocomotive in depou sunt:\n");
          while(var!=NULL)
          {
               printf("\t%d\n",var->numar);
               var=var->urmator;
          }
     printf("\n");
     }
     else
     printf("\nDepou gol!");
}

int main()
{
     int i=0;
     depou=NULL;
     printf(" \n1. Introducere locomotiva in depou");
     printf(" \n2. Scoate locomotiva din depou");
     printf(" \n3. Afisare depou");
     printf(" \n4. Iesire\n");
     while(1)
     {
          printf(" \nAlege optiunea: ");
          scanf("%d",&i);
          switch(i)
          {
               case 1:
               {
               int value;
               printf("\nIntroduceti numarul locomotivei: ");
               scanf("%d",&value);
               introducere_tren(value);
               afisare_depou();
               break;
               }
               case 2:
               {
               eliminare_tren();
               afisare_depou();
               break;
               }
               case 3:
               {
               afisare_depou();
               break;
               }
               case 4:
               {
               struct Tren *temp;
               while(depou!=NULL)
               {
                    temp = depou->urmator;
                    free(depou);
                    depou=temp;
               }
               exit(0);
               }
               default:
               {
               printf("\nNu exista optiunea");
               }
         }
    }
}
