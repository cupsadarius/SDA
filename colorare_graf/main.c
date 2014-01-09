#include <stdio.h>
#include <stdlib.h>
int a[100][100], x[100];
int m,n;
void citire_graf()
{
        int i,j;
        FILE *f;
        f=fopen("graf.txt","r");
        if (f==0) printf("Nu pot deschide fisierul");
        fscanf(f,"%d",&m);
        fscanf(f,"%d",&n);
        for (i=0;i<n;i++)
             { printf("\n");
             for (j=0;j<n;j++)
              {fscanf(f,"%d", &a[i][j]);
               printf(" %d ",a[i][j]);
              }
             }

}

int bun (int k)
{
    int i,j;
    for (i=0; i<k; i++)
            if (a[k][i]==1 && x[k]==x[i] )
                return 0;
    return 1;
}
FILE *out;
void colorare(int k)
{
       int j;

       for (j=1;j<=m;j++)
       {
            x[k]=j;
            if (bun(k))
                if (k<n-1)
                {
                colorare(k+1);
                }
                else{
                    fprintf(out,"\n\nsolutie\n");
                    int h=0;
                    for (h;h<n;h++)
                        fprintf(out," %d ", x[h]);
                }
       }
}
int main()
{
    out = fopen("color_sol.txt","w");
    citire_graf();
    colorare(0);
    fclose(out);
    return 0;
}
