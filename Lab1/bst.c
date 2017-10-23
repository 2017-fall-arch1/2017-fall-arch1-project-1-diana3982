#ifndef bst_include
#define bst_included
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

Node* NewEmployee(char* emp){ /*we take in the new employee*/
  //printf("%s\n%s\n",emp, " is being added");
  Node *newEmp;
  newEmp = (Node*)malloc(sizeof(Node));/*newEmp node*/
  newEmp->name = emp; /* assign the name */
  newEmp->left = NULL;/* create dummy child left*/
  newEmp->right = NULL;/* create dummy chile right*/
  printf("%s%s\n",newEmp->name, " was added");
  return newEmp;
}

Node* Insert(Node *root, char *name){
  //  printf("%s\n%s\n",name, " is being added");

  if(root==NULL){ /*For empty tree */
    return NewEmployee(name);
  }
  else{ /* When we are not at an empty node*/
    printf("%s ", "tree is not empty: ");
    Node* curr = root; /* the current root */
    Node* prev = NULL; /* will be a dummy to reference root*/

    int compare = strcmp(curr->name, name);/* compare name at root to newEmp*/
    prev = curr; /* to reference back to root node*/

    if(compare < 0)/* root is smaller than newEmployee */
    {
      curr = curr->left;
      prev->left = NewEmployee(name);
    }
    else if(compare >= 0)/* The newEmployee is the same as or larger than root */
    {
      curr = curr->right;
      prev->right = NewEmployee(name);
    }
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

  if(root == NULL){
    return;
  }
  if(root != NULL){
    Traverse(root->left);
    printf("%s ,", root->name);
    Traverse(root->right);
  }
}

#endif
