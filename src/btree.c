#include "btree.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


struct tree_node * Insert (int x, struct tree_node *t)
{
  if (Empty(t))  //it  the list is empty then we just insert our leaf on our NULL pointer t
  {
    struct tree_node *leaf = malloc(sizeof(struct tree_node));
      leaf->item=x;
      leaf->left=NULL;
      leaf->right=NULL;

    t->left=leaf;
    t->right=leaf;

  }
  if (Empty(t)==false)

  //if the tree is not empty then we have to place the new node at the right point.
  //we tjek if x is greater or smaller than current->item where current is the pointer that runs thrugh the code.
  //if current finds the right place then we allocate memory to the new node.

  {
  struct tree_node* current = t->left;
  bool isinsert = false;

  while (isinsert==false)
  {
  if (current->item>x)
  {
    if (current->left!=NULL)
    {
      current=current->left;
    }
    else
    {
      struct tree_node *leaf = malloc(sizeof(struct tree_node));
      isinsert=true;
      current->left=leaf;
      leaf->item=x;
      leaf->left=NULL;
      leaf->right=NULL;
    }
  } 
  if (current->item<x)
  {
    if (current->right!=NULL)
    {
      current=current->right;
    }
    else
    {
      struct tree_node *leaf = malloc(sizeof(struct tree_node));
      isinsert=true;
      current->right=leaf;
      leaf->item=x;
      leaf->left=NULL;
      leaf->right=NULL;
    }
  }
  }
  return NULL;
}
}

struct tree_node * Remove (int x, struct tree_node *t)
{

  struct tree_node *current = t;
  struct tree_node *forcurrent = t;
  struct tree_node *root = t;
  struct tree_node *forroot = t;

// this is some helping pointers so we dont have to change t.
  

  int i=0;

  while (i==0)  //this while loop finds the node we want to remove.
  {

    if (current->item==x)
    {
      i=1;
    }
  
    if (current->item>x)
    {
      forcurrent=current;
      current=current->left;
    }
    
    if (current->item<x)
    {
      forcurrent=current;
      current=current->right;
    }
  }

  if (current->left==NULL && current->right==NULL)

  //now we remove x if x have 0 children 

  {
    if (forcurrent->item<x)
    {
      forcurrent->right=NULL;
    }
    else if (forcurrent->item>x)
    {
      forcurrent->left=NULL;
    }
    free (current);
    
  }

  if (current->left !=NULL && current->right==NULL)

  //here we remove x if x only have a left child

  {

    if (forcurrent->item>x)
    {
      forcurrent->left=current->left;
    }

    else if (forcurrent->item<x)
    {
      forcurrent->right=current->left;
    }
  free (current);
  return 0;
  }

  if (current->left==NULL && current->right!=NULL)

  //here we remove x if x only have a right child

  {
    if (forcurrent->item>x)
    {
      forcurrent->left=current->right;
    }
    if (forcurrent->item<x)
    {
      forcurrent->right=current->right;
    }
  free (current);
  return 0;
  }

  if (current->left!=NULL && current->right!=NULL)

  //here we remove x if x have two children.

  {

    root=current->left;

      if (root->right==NULL)
      {
        current->item=root->item;
        current->left=root->left;
        free (root);
      }
      if (root->right!=NULL)
      {
        while (root->right!=NULL)
        {
          forroot=root;
          root=root->right;
        }
    
        forroot->right=root->left;
        current->item=root->item;
        free (root);
      }
 }
}

int Contains (int x, struct tree_node *t)
{

  while (1)
  {
    if (t==NULL)   //if the list is empty then x in not in the list
    {
      return false;
    }

    if (t->item==x)  //if t holds x then x is in the list.
    {
      return 1;
    }
    
    //we go down the rigt way till we get to the place where x must be. this is a loop where we relocate the pointer t every time we go thugh the loop.

    if (t->item>x)
    {
      t=t->left;
    }
    
    if (t->item<x)
    {
      t=t->right;
    }
  }
return 0;
}


struct tree_node * Initialize (struct tree_node *t)

//making a "NULL node" we will later meke this point to the first element in the list.

{
  struct tree_node *d = malloc(sizeof(struct tree_node));
    d->item=-1;
    d->left=NULL;
    d->right=NULL;
  return d;
}

int Empty (struct tree_node *t)
{

//if our pointer have 0 children then the list must be empty because we start with a NULL pointer

if (t->left==NULL && t->right==NULL)
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
