#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
     struct node *previous;
     int data;
     struct node *next;
}*head, *last;

void insert_begning(int value)
{
    struct node *var,*temp;
     var=(struct node *)malloc(sizeof(struct node));
     var->data=value;
     if(head==NULL)
     {
         head=var;
         head->previous=NULL;
         head->next=NULL;
         last=head;
     }
     else
     {
         temp=var;
         temp->previous=NULL;
         temp->next=head;
         head->previous=temp;
         head=temp;
     }
}

void insert_end(int value)
{
     struct node *var,*temp;
     var=(struct node *)malloc(sizeof(struct node));
             var->data=value;
     if(head==NULL)
     {
          head=var;
          head->previous=NULL;
          head->next=NULL;
          last=head;
     }
     else
     {
         last=head;
         while(last!=NULL)
         {
             temp=last;
             last=last->next;
         }
     last=var;
     temp->next=last;
     last->previous=temp;
     last->next=NULL;
     }
}

int insert_after(int value, int loc)
{
     struct node *temp,*var,*temp1;
     var=(struct node *)malloc(sizeof(struct node));
     var->data=value;
         if(head==NULL)
     {
           head=var;
           head->previous=NULL;
           head->next=NULL;
     }
     else
     {
           temp=head;
           while(temp!=NULL && temp->data!=loc)
           {
                 temp=temp->next;
           }
           if(temp==NULL)
           {
                printf("\n%d is not present in list ",loc);
           }
           else
           {
           temp1=temp->next;
           temp->next=var;
           var->previous=temp;
          var->next=temp1;
           temp1->previous=var;
           }
     }
     last=head;
     while(last->next!=NULL)
     {
           last=last->next;
     }
}
int delete_from_end()
{
      struct node *temp;
      temp=last;
      if(temp->previous==NULL)
      {
           free(temp);
           head=NULL;
           last=NULL;
           return 0;
      }
      printf("\nData deleted from list is %d \n",last->data);
      last=temp->previous;
      last->next=NULL;
      free(temp);
      return 0;
}
void delete_from_begining(){
{
    struct node *q;
    q=head;
    head=q->next;
    head->previous=NULL;
    free(q);
    printf("    \nFirst node has ben deleted\n");
    display();
}
}

int delete_from_middle(int key)
{
    struct node *q,*q1,*q2;
    int ok=1;
    q=head;
    if(q==head && q==last)
    {
       head=NULL;
       last=NULL;
       ok=0;
       free(q);
    }
    else
    {
        while(q!=NULL)
        {
            if(q->data==key){
                break;
                ok = 0;
            }else
                q=q->next;
            if((q == last) && (ok == 1)){
              printf("The value has not been found!");
              return 0;
            }
        }
    }
    if(q->data==key)
    {
        q1=q->previous;
        q2=q->next;
        q1->next=q2;
        q2->previous=q1;
        free(q);
        ok=0;
    }
    if(ok==1)
        printf("\n    The node with the key %d has not been found\n",key);
    else
        printf("\n    The node with the key %d has been deleted\n",key);
    return  0;
}

void display()
{
     struct node *temp;
     temp=head;
     if(temp==NULL)
      {
         printf("List is Empty");
      }
     while(temp!=NULL)
     {
          printf("-> %d ",temp->data);
          temp=temp->next;
     }
}

int main()
{
    int value, i, loc;
    head=NULL;
    printf("Select the choice of operation on link list");
    printf("\n1.) insert at begning\n2.) insert at end\n3.) insert at middle");
    printf("\n4.) delete from end\n5.) delete by given key\n6.) delete from begining\n7.) display list\n8.) exit");
    while(1)
    {
          printf("\n\nenter the choice of operation you want to do ");
          scanf("%d",&i);
          switch(i)
          {
                case 1:
                {
                 printf("enter the value you want to insert in node ");
                 scanf("%d",&value);
                 insert_begning(value);
                 display();
                 break;
                 }
                 case 2:
                 {
                 printf("enter the value you want to insert in node at last ");
                 scanf("%d",&value);
                 insert_end(value);
                 display();
                 break;
                 }
                 case 3:
                 {
                 printf("after which data you want to insert data ");
                 scanf("%d",&loc);
                 printf("enter the data you want to insert in list ");
                 scanf("%d",&value);
                 insert_after(value,loc);
                 display();
                 break;
                 }
                 case 4:
                 {
                 delete_from_end();
                 display();
                 break;
                 }
                 case 5:
                 {
                 printf("enter the value you want to delete");
                 scanf("%d",&value);
                 delete_from_middle(value);
                 display();
                 break;
                 }
                 case 6 :
                    delete_from_begining();
                    break;
                 case 7 :
                 {
                 display();
                 break;
                 }
                 case 8 :
                 {
                      exit(0);
                      break;
                 }
          }
    }
    printf("\n\n%d",last->data);
    display();
    getch();
}
