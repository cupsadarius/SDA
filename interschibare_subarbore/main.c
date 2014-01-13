/*
    3.9	Să se scrie un program care să interschimbe subarborele drept cu cel stâng pentru un nod dat.

    Facem citirea arborelui din fisier
    Se alege un nod
    se verifica daca acesta este frunza,
    daca nu se interschimba subarborele drept cu cel stang.

Afisarea se face in ordine.


ARBORELE FOLOSIT:

                  5
            /          \
           3             4
         /   \         /   \
       13    10       21    23
       /    /  \     /  \    \
      20   8   14   24  30   25

*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
    int key;
    struct TREE_NODE *left,*right;
} TREE_NODE;

TREE_NODE *src,*q,*t;
FILE *inputFile;
int ok=1;
void inorder(TREE_NODE *p,int level)
{
    int i;
    if (p!=0){
        inorder(p->left,level+1);
        printf("%2d\n",p->key);
        for(i=0;i<=level;i++)
            printf(" ");
        inorder(p->right,level+1);
    }
}
void display(TREE_NODE *p,int key)
{
    if(p!=0)
    {
        if(p->key==key )
        {
            ok=0;
            if(p->left!=0 && p->right!=0)
            {
                q=p->left;
                t=p->right;
                p->right=q;
                p->left=t;
                inorder(p,0);
            }
            else
                printf("\nNodul %d este o frunza ... nu exista subarbore de inversat\n",p->key);
        }
        else
        {
            display(p->left,key);
            display(p->right,key);
        }
    }
}
TREE_NODE *create()
{
    TREE_NODE *p;
    int inf;
    fscanf(inputFile,"%d",&inf);
    if(inf==0) return 0;
    else
    {
        p=(TREE_NODE*)malloc(sizeof(TREE_NODE));
        p->key=inf;
        p->left=create();
        p->right=create();
    }
    return p;
}
int main()
{
    inputFile=fopen("tree.txt","r");
    int i=1;
    do
    {
        printf("Alegeti optiune:\n1\t->\tCitire arbore din fisier\n2\t->\tParcurgere in ordine\n3\t-<\tSchimbare subarbore\n");
        scanf("%d",&i);
        switch (i){
        case 1:
            src=create();
            break;
        case 2:
            printf("\nParcurgere in ordine\n");
            inorder(src,0);
            printf("\n");
            break;
        case 3:
        {
            int key;
            printf("Cititi un nod din arbore: ");
            scanf("%d",&key);
            if(ok == 1)
                printf("Nodul nu se afla in arbore\n");
            else
                printf("\nParcurgere in ordine dupa schimbare subarbori\n");
            display(src,key);
            break;
        }
        default:
            printf("\nOptiune inexistenta!");
            i=0;}
    }while(i);
    fclose(inputFile);
    return 0;
}
