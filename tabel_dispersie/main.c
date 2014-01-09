// open adress hash table
#include <stdio.h>
#include <stdlib.h>

#define Size 13

struct  node
{
	/* data */
	int data;
	char *s;
};
//double hashing
int hash_function(int k, int i){
	int a,b,c;
	a = k % Size; //first hash function
	b = 1+(k%(Size-2)); // second hash function
	c = (a+i*b)%Size;
	return c;
}

int hash_search(struct node T[], int k){
	int i,j;
	i = 0;
	while(i!=Size) {
	    j = hash_function(k,i);
	    if(T[j].data == k && T[j].s == "FULL"){
	    	return j;
	    }
	    i++;
	}
	return -1;
}

void hash_delete(struct node *T, int k){
	int i,j;
	i = hash_function(T,k);
	if(i != -1){
		T[i].s = "DELETED";
	} else {
		printf("Element not found in hash table\n");
	}
	return;
}

void hash_insert(struct node *T, int k){
	int i,j;
	i = 0;
	while (i != Size){
		j = hash_function(k,i);
		if(T[j].s == "NULL" || T[j].s == "DELETED"){
			T[j].data = k;
			T[j].s = "FULL";
			return;
		}
		i++;
	}
	if (i == Size){
		printf("Hash table full -> overflow\n");
	}
	return;
}

int main(){
	int i,j,a,op = 1;
	struct node T[Size];
	for (i = 0; i< Size; i++) T[i].s = "NULL";
	do {
		printf("Table options\n\n");
		printf("1 -> Insert\n");
		printf("2 -> Delete\n");
		printf("3 -> Display\n");
		printf("4 -> Search\n\n");
		printf("5 -> Exit\n\n");
		scanf("%d",&op);

		switch(op){
			case 1:
				printf("Enter the element you want to insert: ");
				scanf("%d",&a);
				hash_insert(T,a);
				printf("\n");
				break;
			case 2:
				printf("Enter the element you want to delete: ");
				scanf("%d",&a);
				hash_delete(T,a);
				printf("\n");
				break;
			case 3:
				for(i = 0;i<Size;i++){
					printf("%s", T[i].s);
					if(T[i].s == "FULL") printf(" -> %d\n", T[i].data);
					printf("\n");
				}
				break;
			case 4:
				printf("Enter the element you want to search: ");
				scanf("%d",&a);
				i = hash_search(T,a);
				printf("Element %d is present in table at %d position\n", a,i);
				printf("\n");
				break;
			case 5: break;
			default:
				printf("Wrong choice!\n");
				break;
				break;

		}
	} while(op != 5);
	return 0;
}
