#include<stdio.h>
#include<stdlib.h>

struct node
{
int INFO;
struct node *LINK;
};

typedef struct node NODE;
NODE *start=NULL; 

void display( )
{
NODE *CURRPTR = start;
if (start == NULL) /* Calling display without creating the nodes */
printf("\n The Linked list is empty");
else
{
while (CURRPTR != NULL) /* Traversing till the end of list */
{
printf("%d", CURRPTR->INFO);
printf("->");
CURRPTR = CURRPTR -> LINK; /*Making CURRPTR to point to the next node
pointed by CURRPTR */ 
}
printf("NULL");
}
}

void create( )
{
char ch;
int i = 0;
NODE *CURRPTR, *NEWNODE;
CURRPTR = (NODE *) malloc (sizeof(NODE));
start = CURRPTR;
while (1)
{
printf("\n Enter the node %d : ", i + 1);
scanf ("%d", & CURRPTR->INFO); /* Element entry into the INFO field of CURRPTR*/
printf("\n Do you wish to add one more node (Y/N) : ");
ch = getche();
if (toupper(ch) == 'Y') /* If one more node is required */
{
NEWNODE = (NODE *) malloc (sizeof(NODE)); // allocate required memory
CURRPTR ->LINK = NEWNODE; // make link between previous node and newnode
CURRPTR = NEWNODE;
}
else /* if no more nodes are required */
{
CURRPTR -> LINK = NULL; // Finally, make link of last node (CURRPTR) to NULL
break;
}
i++;
}
}

void main()
{
printf("\n\t\t Creation of linked list");
printf("\n\t\t--------------------------");
create(); /* creates linked list */
printf("\nThe linked list created is: ");
display();
}


