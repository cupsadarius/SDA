#include <stdio.h>
#include <stdlib.h>

//Structure containing a Data part & a
//Link part to the next node in the List

typedef struct node_type
{
    int Data;
    struct node_type *Next;
}NOD;


NOD *Head = NULL;
// Counting number of elements in the List

int length()
{
  NOD *current_node;
  int count=0;

  current_node=Head;

  while(current_node != NULL)
  {
     current_node=current_node->Next;
     count++;
  }
  return(count);
}

// Deleting a node from List depending upon the data in the node.

int delNodeData(int num)
{
  NOD *prev_node, *current_node;

  current_node=Head;

  while(current_node != NULL)
  {
     if(current_node->Data == num)
     {
        if(current_node==Head)
        {
           Head=current_node->Next;
           free(current_node);
           return 0;
        }
        else
        {
           prev_node->Next=current_node->Next;
           free(current_node);
           return 0;
        }
     }
     else
     {
        prev_node=current_node;
        current_node=current_node->Next;
     }
  }

  printf("\nElement %d is not found in the List", num);
  return 1;
}

// Deleting a node from List depending upon the location in the list.

int delNodeLoc(int loc)
{
  NOD *prev_node, *current_node;
  int i;

  current_node=Head;

  if(loc > (length()) || loc <= 0)
  {
      printf("\nDeletion of Node at given location is not possible\n ");
  }
  else
  {
      // If the location is starting of the list
      if (loc == 1)
      {
          Head=current_node->Next;
          free(current_node);
          return 0;
      }
      else
      {
          for(i=1;i<loc;i++)
          {
              prev_node=current_node;
              current_node=current_node->Next;
          }

          prev_node->Next=current_node->Next;
          free(current_node);
      }
  }
  return 1;
}

//Adding a Node at the end of the list

void addEnd(int num)
{
  NOD *temp1, *temp2;

  temp1=(NOD *)malloc(sizeof(NOD));
  temp1->Data=num;

  // Copying the Head location into another node.
  temp2=Head;

  if(Head == NULL)
  {
     // If List is empty we create First Node.
     Head=temp1;
     Head->Next=NULL;
  }
  else
  {
     // Traverse down to end of the list.
     while(temp2->Next != NULL)
     temp2=temp2->Next;

     // Append at the end of the list.
     temp1->Next=NULL;
     temp2->Next=temp1;
  }
}

// Adding a Node at the Beginning of the List

void addBeg(int num)
{
  NOD *temp;

  temp=(NOD *)malloc(sizeof(NOD));
  temp->Data = num;

  if (Head == NULL)
  {
     //List is Empty
     Head=temp;
     Head->Next=NULL;
  }
  else
  {
     temp->Next=Head;
     Head=temp;
  }
}

// Adding a new Node at specified position

void addAt(int num, int loc)
{
  int i;
  NOD *temp, *prev_node, *current_node;

  current_node=Head;

  if(loc > (length()+1) || loc <= 0)
  {
     printf("\nInsertion at given location is not possible\n ");
  }
  else
  {
      // If the location is starting of the list
      if (loc == 1)
      {
          addBeg(num);
      }
      else
      {
          for(i=1;i<loc;i++)
          {
              prev_node=current_node;
              current_node=current_node->Next;
          }

          temp=(NOD *)malloc(sizeof(NOD));
          temp->Data=num;

          prev_node->Next=temp;
          temp->Next=current_node;
      }
  }
}

// Displaying list contents

void display()
{
  NOD *current_node;

  current_node=Head;

  if(current_node==NULL)
  {
     printf("\nList is Empty");
  }
  else
  {
      printf("\nElements in the List: ");
      //traverse the entire linked list
      while(current_node!=NULL)
      {
          printf(" -> %d ",current_node->Data);
          current_node=current_node->Next;
      }
      printf("\n");
  }
}

//Reversesing a Linked List

void reverse()
{
  NOD *prev_node, *current_node, *temp;

  current_node=Head;
  prev_node=NULL;

  while(current_node != NULL)
  {
     temp=prev_node;
     prev_node=current_node;

     current_node=current_node->Next;
     prev_node->Next=temp;
  }

  Head=prev_node;
}


int main()
{
 int i=0;



 while(1)
 {
    printf("\n####################################################\n");
    printf("Aviable Options\n");
    printf("####################################################\n");
    printf(" \nInsert a number \n1. At the Beginning");
    printf(" \n2. At the End");
    printf(" \n3. At a Particular Location in the List");
    printf(" \n\n4. Print the Elements in the List");
    printf(" \n5. Print number of elements in the List");
    printf(" \n6. Reverse the linked List");
    printf(" \n\nDelete a Node in the List");
    printf(" \n7. Delete a node based on Value");
    printf(" \n8. Delete a node based on Location\n");
    printf(" \n\n9. Clear Screen");
    printf(" \n0. Exit\n");
    printf(" \nChoose Option: ");
    scanf("%d",&i);

    switch(i)
    {
      case 1:
      {
          int num;
          printf(" \nEnter a Number to insert in the List: ");
          scanf("%d",&num);
          addBeg(num);
          display();
          break;
      }

      case 2:
      {
          int num;
          printf(" \nEnter the Number to insert: ");
          scanf("%d",&num);
          addEnd(num);
          display();
          break;
      }

      case 3:
      {
          int num, loc;
          printf("\nEnter the Number to insert: ");
          scanf("%d",&num);
          printf("\nEnter the location Number in List at which the Number is inserted: ");
          scanf("%d",&loc);
          addAt(num,loc);
          display();
          break;
      }

      case 4:
      {
          display();
          break;
      }

      case 5:
      {
          display();
          printf(" \nTotal number of nodes in the List: %d",length());
          break;
      }

      case 6:
      {
          reverse();
          display();
          break;
      }

      case 7:
      {
          int num;
          printf(" \nEnter the number to be deleted from List: ");
          scanf("%d",&num);
          delNodeData(num);
          display();
          break;
      }

      case 8:
      {
          int num;
          printf(" \nEnter the location of the node to be deleted from List: ");
          scanf("%d",&num);
          delNodeLoc(num);
          display();
          break;
      }
      case 9:
          system("clr");
      break;
      case 0:
      {
          struct Node *temp;

          while(Head!=NULL)
          {
              temp = Head->Next;
              free(Head);
              Head=temp;
          }
          exit(0);
      }

      default:
      {
          printf("\nWrong Option choosen");
      }
    }/* end if switch */
 }/* end of while */
}/* end of main */
