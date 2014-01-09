#include<stdio.h>
#include<stdlib.h>

typedef struct node_type
{
	char id;
	struct node_type *left, *right;
}NodeT;

void fatalError(const char *msg)
{
	printf(msg);
	printf("\n");
	exit(1);
}
void preorder(NodeT *p,int level)
{
	int i;
	if(p!=NULL)
	{
		for(i=0;i<=level;i++) printf(" ");
		printf("%d",p->id);
		preorder(p->left,level+1);
		preorder(p->right,level+1);
	}
}
void inorder(NodeT *p,int level)
{
	int i;
	if(p!=NULL)
	{
		inorder(p->left,level+1);
		for(i=0;i<=level;i++)
			printf(" ");/*fornicelisting*/
		printf("%d\n",p->id);
		inorder(p->right,level+1);
	}
}
void postorder(NodeT *p,int level)
{
	int i;
	if(p!=NULL)
	{
		postorder(p->left,level+1);
		postorder(p->right,level+1);
		for(i=0;i<=level;i++)
			printf(" ");/*fornicelisting*/
		printf("%d\n",p->id);
	}
}
NodeT *createBinTree(int branch,NodeT *parent)
{
	NodeT *p;
	int id;
	/*readnodeid*/
	if(branch==0)
		printf("Root identifier=");
	else if(branch==1)
		printf("Left child of %d=",parent->id);
	else
	printf("Right child of %d=",parent->id);
	scanf("%d",&id);
	if(id==0)	return NULL;
	else{
		p=(NodeT*)malloc(sizeof(NodeT));
		if(p==NULL)
		fatalError("Out of space in create BinTree");
		/*fillinnode*/
		p->id=id;
		p->left=createBinTree(1,p);
		p->right=createBinTree(2,p);
	}
	return p;
}
int main()
{
	NodeT *root;
	root=createBinTree(0,NULL);
	while('\n'!=getc(stdin));
	printf("\nPreorder listing\n");
	preorder(root,0);
	printf("\nPress Enter to continue.");
	while('\n'!=getc(stdin));
	printf("\nIn order listing\n");
	inorder(root,0);
	printf("\nPress Enter to continue.");
	while('\n'!=getc(stdin));
	printf("\nPost order listing\n");
	postorder(root,0);
	printf("\nPress Enter to continue.");
	while('\n'!=getc(stdin));
	return 0;
}
