
#include <stdio.h>
#include <stdlib.h>

typedef struct tren{
	int key;
	struct tren *next;
}depou;

depou *first, *last, *dep;

depou *creare_locomotiva(int key){
	depou *tren_nou;
	if (key == 0){
		printf("Introduceti numarul locomotivei: ");
		scanf("%d", &key);
	}
	tren_nou = (depou *)malloc(sizeof(depou));
	tren_nou->key = key;
	tren_nou->next = NULL;
	return tren_nou;
}

void adaugare_locomotiva(depou *tren_nou){
	if (tren_nou == NULL){
		tren_nou = creare_locomotiva(0);
	}
	tren_nou->next = NULL;
	last->next = tren_nou;
	last = tren_nou;
}

void initializare_depou(){
	depou *tren_nou;
	FILE *f;
	first = (depou *)malloc(sizeof(depou));
	last = (depou *)malloc(sizeof(depou));
	if (!(f = fopen("depou.txt", "r"))){
		printf("Nu pot initializa depoul din fisier!");
		tren_nou = creare_locomotiva(0);
		adaugare_locomotiva(tren_nou);
		first = tren_nou;

	}
	else {
		int n, key, i;
		fscanf(f, "%d", &n);
		for (i = 0; i < n; i++){
			fscanf(f, "%d", &key);
			if (i == 0){
				dep = creare_locomotiva(key);
				first = dep;
				last = dep;
			}
			else {
				tren_nou = creare_locomotiva(key);
				adaugare_locomotiva(tren_nou);
			}
		}
	}
}

void afisare_depou(depou *temp){
	system("cls");
	printf("\n\tAfisare depou: \n");
	while (temp){
		printf("%d <- ", temp->key);
		temp = temp->next;
	}
}

void pop(int la_final){
	depou *temp = dep;
	dep = dep->next;
	first = dep;
	if(la_final == 1) {
        adaugare_locomotiva(temp);
	} else {
        free(temp);
	}
}


void scoate_locomotiva(){
	int key;
	depou *temp, *inf;
	printf("Introduceti numarul locomotivei pe care vreti sa o scoateti: ");
	scanf("%d", &key);
	temp = dep;
	if (dep->key == key){
		pop(0);
	}
	else {
		while (temp->key != key){
			temp = temp->next;
			pop(1);
		}
		pop(0);
	}
}



int main()
{
	int opt;
	depou *tren_nou;
	do {
		printf("\n\n1  -  Initializare depou.\n");
		printf("2  -  Introduce o locomotiva\n");
		printf("3  -  Scoate o locomotiva dupa numar\n");
		printf("4  -  Afisare depou\n");
		printf("0  -  Iesire\n\n");
		printf("\n Alege optiunea: ");
		scanf("%d", &opt);

		switch (opt) {
		case 1:
			initializare_depou();
			afisare_depou(first);
			break;
		case 2:
			tren_nou = creare_locomotiva(0);
			adaugare_locomotiva(tren_nou);
			afisare_depou(first);
			break;
		case 3:
			scoate_locomotiva();
			afisare_depou(first);
			break;
		case 4:
			afisare_depou(first);
			break;

		default: printf("Operatia nu exita!");

		}
		//system("cls");

	} while (opt != 0);
	return 0;
}

