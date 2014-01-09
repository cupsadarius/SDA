#include <stdio.h>
#include <stdlib.h>

struct node
{
      int data;
      struct node *next;
};
struct node *start;

void insertbeg(void)
{
      struct node *nn,*temp;int a;
      nn=(struct node *)malloc(sizeof(struct node));
      printf("enter data:");
      scanf("%d",&nn->data);
      a=nn->data;
      if(start==NULL)
      {
            nn->next=nn;
            start=nn;
      }
      else
      {
            temp=start;
            while(temp->next!=start)
            {
                  temp=temp->next;
            }
            temp->next=nn;
            nn->next=start;
            start=nn;
      }
      printf("%d succ. inserted\n",a);
      return;
}

void insertend(void)
{
      struct node *nn,*lp;int b;
      nn=(struct node *)malloc(sizeof(struct node));
      printf("enter data:");
      scanf("%d",&nn->data);
      b=nn->data;
      if(start==NULL)
      {
            nn->next=nn;
            start=nn;
      }
      else
      {
            lp=start;
            while(lp->next!=start)
            {
                  lp=lp->next;
            }
            lp->next=nn;
            nn->next=start;
      }
      printf("%d is succ. inserted\n",b);
      return;
}

void insertmid(void)
{
      struct node *nn,*temp,*ptemp;int x,v;
      nn=(struct node *)malloc(sizeof(struct node));
      if(start==NULL)
      {
            printf("sll is empty\n"); return;
      }
      printf("enter data before which no. is to be inserted:\n");
      scanf("%d",&x);
      if(x==start->data)
      {
            insertbeg();
            return;
      }
      ptemp=start;
      temp=start->next;
      while(temp!=start&&temp->data!=x)
      {
            ptemp=temp;
            temp=temp->next;
      }
      if(temp==start)
      {
            printf("%d data does not exist\n",x);
      }
      else
      {
            printf("enter data:");
            scanf("%d",&nn->data);
            v=nn->data;
            ptemp->next=nn;
            nn->next=temp;
            printf("%d succ. inserted\n",v);
      }
      return;
}

void deletion(void)
{
      struct node *pt,*t,*pp;
      int x;
      if(start==NULL)
      {
            printf("sll is empty\n");
            return;
      }
      printf("enter data to be deleted:");
      scanf("%d",&x);
      if(x==start->data)
      {
            pp=t=start;
if(start->next==start)
                {
   free(pp);
          start=NULL;
    printf("%d succ. deleted",x);
   return;
                }
            while(t->next!=start)
            {
                  t=t->next;
            }
            t->next=start->next;
            start=start->next;
            free(pp);
            printf("%d is succ. deleted\n",x);
            return;
     }
      pt=start;
      t=start->next;
      while(t!=start&&t->data!=x)
      {
            pt=t;t=t->next;
      }
      if(t==start)
      {
            printf("%d does not exist\n",x);return;
      }
      else
      {
            pt->next=t->next;
      }
      printf("%d is succ. deleted\n",x);
      free(t);
      return;
}

void display(void)
{
      struct node *temp;
      if(start==NULL)
      {
            printf("list is empty\n");
            return;
      }
      printf("\nelements are:\n");
      temp=start;
      while(temp->next!=start)
      {
            printf("%d -> ",temp->data);
            temp=temp->next;
      }
      printf("%d\n",temp->data);
      return;
}

void main()
{
      int c,a; start=NULL;
      do
      {
            printf("\n1:insert\n2:delete\n3:display\n\n4:exit\nenter choice:");
            scanf("%d",&c);
            switch(c)
            {
                  case 1:
                              printf("\n1:insert beginig\n2:insert end\n3:insert mid\nenter choice:");
                              scanf("%d",&a);
                              switch(a)
                              {
                                   case 1:insertbeg();break;
                                   case 2:insertend();break;
                                   case 3:insertmid();break;
                              }
                              break;
                  case 2:deletion();break;
                  case 3:display();break;
                  case 4:printf("program ends\n");break;
                  default:printf("wrong choice\n");
                  break;
            }
     }while(c!=4);
}
