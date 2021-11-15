#include "linked_list.h"
/*
 * Linked list
 */

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* malloc, free */
#include <assert.h>		/* assert */

/* functions to create lists */
node *make_node (int v, node * q)
{
  node *p = malloc (sizeof (node));
  p->value = v;

  if (q == &SENTINEL_node)
    p->next = &SENTINEL_node;
  else
    p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list (node ** p)
{
  node *q = *p;
  while (q != &SENTINEL_node)
    {
      node *t = q->next;
      free (q);
      q = t;
    }
    (*p) = NULL;
}


/* print list to console */
void print_list (node * p)

// printing our value and goes to the next element in the list

{
  if (p->next!=NULL)
  {
    printf("%d", p->value);
    print_list (p->next);
  }
  else
  {
    printf("%d", p->value);
  }

}

int sum_squares (node * p)

// making a recrusiv funktion for squaring our linked list.

{
if (p->next!=NULL)
{
  return ((p->value*p->value)+sum_squares(p->next));
}
else
{
  return(p->value*p->value);
}
}

node *map (node * p, int (*f) (int))

//mapping our new list in a linked list

{
if (p==NULL)
{
  return NULL;
}
else
{
  node *item = malloc(sizeof(node));
  item->value=f(p->value);
  item->next=map (p->next, f);
  return item;
}


return NULL;
}


int square (int x)
{
  return x * x;
}
