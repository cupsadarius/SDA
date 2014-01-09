#include <stdio.h>
#include <stdlib.h>

typedef struct tip_nod{
    int key;
    struct tip_nod *next;
} NOD;

//Variabile Globale
NOD *lista, *first, *last;

//calculating the length of the list
int length(){
    NOD *p;
    int i = 0;
    p = first;
    while(p){
        i++;
        p = p->next;
    }
    return i;

}
//Creating a node
NOD *create_node(){
    NOD *nod_nou;
    if(!(nod_nou = (NOD *)malloc(sizeof(NOD)))){
        return NULL;
    } else{
       int key;
        printf("Please enter a value: ");
        scanf("%d",&key);
        nod_nou->next = NULL;
        nod_nou->key = key;
        return nod_nou;
    }
}

//creating the root of the list
void create_list(){

    first = (NOD *)malloc(sizeof(NOD));
    last = (NOD *)malloc(sizeof(NOD));
    if(!(lista = create_node())) {
        printf("Can't initialize list!");
    } else {
        first = lista;
        last = lista;
        show_list(first);
    }
}
//add an item at the begining of the list
void add_item_begining(){
    NOD *nod_nou;
    if(!(nod_nou = create_node())){
        printf("Can't add new node at the begining");
    } else {
        nod_nou->next = lista;
        first = nod_nou;
        lista = first;
        show_list(first);
    }
}
//add an item at the end of the list
void add_item_after(){
    NOD *nod_nou;
    if(!(nod_nou = create_node())){
        printf("Can't add new node at the end");
    } else {
        nod_nou->next = last->next;
        last->next = nod_nou;
        last = nod_nou;
        show_list(first);
    }
}
//add an item on a specified position
void add_item_on_position(){
    NOD *nod_nou , *prev, *current;
    int pos, i;
    current = lista;
    printf("%d %d",first->key,lista->key);
    printf("On which position do you want to add: ");
    scanf("%d",&pos);
    if(pos == 1){
        add_item_begining();
    } else {
        for(i=1;i<pos;i++){
            prev = current;
            current = current->next;
        }
        nod_nou = create_node();
        prev->next = nod_nou;
        nod_nou->next = current;
    }
    show_list();
}

void delete_item_value(){
    int key;
    NOD *temp;
    printf("please enter the key which you want to be removed: ");
    scanf("%d",&key);
    while(lista){
        if(lista->next->key == key){
            temp = lista->next;
            lista->next = lista->next->next;
            free(temp);
        }
        lista = lista->next;
    }
    show_list(lista);

}

void show_list(NOD *p){
    system("cls");
    while(p){
        printf("%d - ",p->key);
        p = p->next;
    }

}
int main()
{
    int opt;
    do {
        printf("\n\nWelcome!\n\n");
        printf("Operations\n");
        printf("1  -  Create a new list.\n");
        printf("2  -  Add a new item at the begining\n");
        printf("3  -  Add a new item at the end\n");
        printf("4  -  Add a new item on a given position\n");
        printf("5  -  Delete an item based on value\n");
        printf("6  -  Delete an item based on it's position\n");
        printf("7  -  Clear the list\n");
        printf("8  -  Show the list\n\n");
        printf("9  -  Clear Screen\n");
        printf("0  -  Exit\n\n");
        printf("\n Please chose an operation: ");
        scanf("%d",&opt);

        switch(opt) {
            case 1 :
                create_list();
            break;
            case 2 :
                add_item_begining();
            break;
            case 3 :
                add_item_after();
            break;
            case 4 :
                add_item_on_position();
            break;
            case 5 :
                delete_item_value();
            break;
            case 6 :
            break;
            case 7 :
            break;
            case 8 :
                show_list(first);
            break;
            case 9 :
                system("cls");
            break;
            case 0 : printf("Thank you!");
            break;
            default : printf("Option does not exist!");

        }
    //system("cls");

    } while (opt != 0);
    return 0;
}
