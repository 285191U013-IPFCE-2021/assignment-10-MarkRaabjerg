#include "btree.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


int min_of_right(struct tree_node *t)

//finding the smallest of the biggest value

{
  struct tree_node * temp = t;
      while (t -> left != NULL)
      {
        temp = t -> left;
      }
  return temp -> item;
} 




struct tree_node * Insert (int x, struct tree_node *t)
{

  struct tree_node * new_x = malloc(sizeof(struct tree_node));

  new_x -> item = x;
  new_x -> right = NULL;
  new_x -> left = NULL;

  if (t == NULL)    //if the tree is empty then the new tree is x
    return new_x;
  
  if (x > t -> item)
    t -> right = Insert(x , t -> right);    //when x is larger than the the current ellement
  else 
    t -> left = Insert(x , t -> left);    //when x is smaller than the current ellement 

  return t;     //returns the tree with item x inside
}

struct tree_node * Remove (int x, struct tree_node *t)
{
  if (t == NULL)    //if the tree is empty we return the empty tree because we cant remove anything
    return t;

  if (x > t->item) 
    {
      t -> right = Remove (x , t -> right); //serching for a pointer to the node that holds x
    }                                       
  else if (x < t -> item)
    {
      t -> left = Remove (x , t -> left);
    }
  else if (t -> left == NULL && t -> right == NULL)     // if x has no children
    {                                               
      free(t);
      return NULL;
    }
      else if (t->right == NULL || t->left == NULL)
      {
        struct tree_node * temp_t = NULL;
        if (t -> right == NULL)
        {
          temp_t = t -> left;
        }
        else if (t -> left == NULL)
          temp_t = t -> right;
        free (t);
        return temp_t;
      } 
     else 
      {
        int min_largest = min_of_right (t->right);          //if x has children we use min_of_right to find the new position for x
        t -> item = min_largest;                        
        t -> right = Remove(t -> item, t -> right);     
      }
  return t;
}

int Contains (int x, struct tree_node *t)
{
    if (t==NULL)   //if the list is empty then x in not in the list
    {
      return 0;
    }

    if (t->item==x)  //if t holds x then x is in the list.
    {
      return 1;
    }
    
    //we go down the right way till we get to the place where x must be. this is a loop where we relocate the pointer t every time we go thugh the loop.

    if (t->item>x)
    {
      return Contains(x, t->left);
    }
    
    if (t->item<x)
    {
      return Contains(x, t->right);
    }
return 0;
}


struct tree_node * Initialize (struct tree_node *t)

//making a "NULL pointer" we will later meke this point to the first element in the list.

{
t=NULL;
return t;
}

int Empty (struct tree_node *t)
{

//if our pointer is NULL the list must be empty

if (t == NULL)
  {
    return 1;    
  }
else
  {
    return 0;
  }
}

int Full (struct tree_node *t)
{
    return 0;
}
// a linked list can not be full
