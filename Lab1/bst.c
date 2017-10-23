#ifndef bst_include
#define bst_included
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

typedef struct Node{
  char* name;
  struct Node* left;
  struct Node* right;
}Node;

Node* NewEmployee(char* emp){ /*we take in the new employee*/
  Node *newEmp = (Node*)malloc(sizeof(Node));/*newEmp node*/
  newEmp->name = emp; /* assign the name */
  newEmp->left = NULL;/* create dummy child left*/
  newEmp->right = NULL;/* create dummy chile right*/
  return newEmp;
}

Node* Insert(Node *root, char *name){

  if(root==NULL){ /*For empty tree */
    return NewEmployee(name);
  }
  else{ /* When we are not at an empty node*/
    int compare = strcmp(root->name, name); /* We check if the names are < = > */

    if(compare < 0)/* root is smaller than newEmployee */
    {
      root->right = Insert(root->right, name); /* try to insert into right node */
    }
    if(compare >= 0)/* The newEmployee is the same as or larger than root */
    {
      root->left = Insert(root->left, name); /* Try to insert into left */
    }
  }
  return root;
}

Node* Delete(Node* root, char* name){

  if(root == NULL){
    return NULL;
  }

  Node *curr;
  int compare = strcmp(root->name,name); /* We check if the names are < = > */

  if(compare < 0){/* root is smaller than the employee */
    root->right = Delete(root->right, name); /* try to insert into right node */
  }

  if(compare > 0){/* The employee larger than the root */
    root->left = Delete(root->left, name); /* Try to insert into left */
  }
  if(compare == 0){/* We found the employee to delete*/
    if(root->left == NULL){
      curr = root->right;/* points to the right child */
      free(root); /* deallocates the memory of the root */;
      root = curr; /*we now make the curr node take place of the previous root */
    }
    else if(root->right == NULL){
      curr = root->left;/* points to the left child */
      free(root); /* deallocates the memory of the root */;
      root = curr; /*we now make the curr node take place of the previous root */
    }
    else{ /* when we have a left and right child */
      curr = root->right;/* we point to the right child  */
      Node *parent = NULL;/* create dummy parent node */

      while(curr->left != NULL){/* the employee to the left of root->right */
        parent = curr; /* parent dummy is right child of the employee to be removed*/
        curr = curr->left;/* curr now points to the smaller employee of the right child */
      }
      root->name = curr->name;/* reassign the name of the root employee */
      if(parent != NULL){
        parent->left = Delete(parent->left,parent->left->name);
      }
      else{
        root->right = Delete(root->right, root->right->name);
      }
    }
  }
  return root;
}

void Traverse(Node *root){ /* Traverse to print employees */
  if(root != NULL){
    Traverse(root->left);
    printf("%s", root->name);
    Traverse(root->right);
  }
}

#endif
