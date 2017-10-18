#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"

Node *NewEmployee(char name){ /*we take in the new employee*/
  Node *newEmp =  (Node*)malloc(sizeof(Node));
  newEmp->name=name;
  newEmp->left=NULL;
  newEmp->right=NULL;
  return newEmp;
}
void Insert(Node* root, char name){
  if(root==NULL){
    root= newEmployee(name);
    return root;
  }
}
