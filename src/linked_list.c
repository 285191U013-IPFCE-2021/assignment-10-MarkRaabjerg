#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* functions to create lists */
node *make_node (int v, node * q)
{
  node *p = malloc (sizeof (node));
  p->value = v;

  if (q == NULL)
    p->next = NULL;
  else
    p->next = q;
  return p;
}

/* free all nodes in the list p */
node * free_list (node * p)
{
  node *q = p;
  while (q != NULL)
    {
      node *t = q->next;
      free (q);
      q = t;
    }
  return q;
}


/* print list to console */
void print_list (node * p)
{
  node *current_node = p;           //local pointer used insted of p

    if (current_node->next == NULL) //base case
    {
        printf("%d\n", current_node->value);
    }
    else //recursive step
    {
      printf("%d\n", current_node->value);
      print_list(current_node->next);       //recursive step
    }
}

int sum_squares (node * p)
{
  if (p == NULL)
    return 0;
  else if (p->next == NULL)
    return square(p->value); //base case
  else
    return sum_squares(p->next)+square(p->value); //recursive step
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
    return make_node((*f) (p->value), map (p->next, f));
  }
}

int square (int x)
{
  return x * x;
}
