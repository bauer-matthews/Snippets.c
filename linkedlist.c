#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct NODE {
    int number;
    struct NODE *next;
};

void print(struct NODE *llist) 
{
    struct NODE *pnode = llist->next;

    printf("< ");

    while (pnode != NULL) 
    {
        printf("%d ", pnode->number);
        pnode = pnode->next;
    }
    printf(">\n");
}

void append(struct NODE *llist, int num) 
{
    while (llist->next != NULL)
    {
        llist = llist->next;
    }

    llist->next = (struct NODE *)malloc(sizeof(struct NODE));
    assert(llist->next != NULL);
    llist->next->number = num;
    llist->next->next = NULL;
}

void prepend(struct NODE *llist, int num) 
{
    struct NODE *pnode;

    pnode = (struct NODE *)malloc(sizeof(struct NODE));
    assert(pnode != NULL);
    pnode->number = num;

    pnode->next = llist->next;
    llist->next = pnode;
}

void delete(struct NODE *llist, int num) 
{
    struct NODE *pnode = llist->next;
    struct NODE *pprev = llist;

    while (pnode != NULL) 
    {
        if (pnode->number == num)
        {
             pprev->next = pnode->next;
             free(pnode);
             return;
        }
        pprev = pnode;
        pnode = pnode->next;
    }
}

int find(struct NODE *llist, int num) 
{
    int location = 1;

    while (llist->next != NULL) 
    {
        if (llist->next->number == num)
            return location;
        location++;
        llist = llist->next;
    }

    return (-1);
}

int length(struct NODE *llist) 
{
    int length = 0;

    while (llist->next != NULL) 
    {
        length++;
        llist = llist->next;
    }

    return (length);
}

int main(void) 
{
    struct NODE *llist;
    struct NODE *pnode;

    int num = 0;
    int input = 1;
    int retval = 0;
      
    // TODO: createList()
    llist = (struct NODE *)malloc(sizeof(struct NODE));
    assert(llist != NULL);
    llist->number = 0;
    llist->next = NULL;
      
    while (input != 0) 
    {
        printf("0 = Quit, 1 = Append, 2 = Prepend, 3 = Delete, 4 = Find, 5 = Print, 6 = Length\n");
        scanf("%d", &input);

       switch(input) 
       {
           case 0: 
               input = 0;
               break;
           case 1:
               printf("Enter a value to append: ");
               scanf("%d", &num);
               append(llist, num);
               break;
           case 2:
               printf("Enter a value to prepend: ");
               scanf("%d", &num);
               prepend(llist, num);
               break;
           case 3:
               printf("Enter a value to delete: ");
               scanf("%d", &num);
               delete(llist, num);
               break;
           case 4:
               printf("Enter a value to find: ");
               scanf("%d", &num);
               if ((retval = find(llist, num)) == -1)
                   printf("Value `%d' not found\n", num);
               else
                   printf("Found value `%d' at position `%d'\n", num, retval);
               break;
          case 5:
               print(llist);
               break;
          case 6:
               printf("List length is %d\n", length(llist));
               break;
          default:
               break;
      } /* switch */
  } /* while */

  // TODO: deleteList()
  pnode = llist->next;
  while (pnode != NULL) 
  {
     pnode->number = 0;
     free(pnode);
     pnode = pnode->next;
  }
  free(llist);

  return(0);
}

