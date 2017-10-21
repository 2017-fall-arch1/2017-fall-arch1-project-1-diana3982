#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"

Node* NewEmployee(char name){ /*we take in the new employee*/
  Node *newEmp = (Node*)malloc(sizeof(Node));
  newEmp->name = name;
  newEmp->left = NULL;
  newEmp->right = NULL;
  return newEmp;
}
Node* Insert(Node *root, char* name){

  if(root==NULL){ /*For empty tree */
    root = newEmployee(name);
  }
  else{ /* When we do not have a empty tree*/
    int compare = strcmp(root,name); /* We check if the names are < = > */

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
