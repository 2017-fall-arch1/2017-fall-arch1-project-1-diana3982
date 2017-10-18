#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"

Node *NewEmployee(char *name){ /*we take in the new employee*/
  Node *newEmp =  (Node*)malloc(sizeof(Node));
  newEmp->name=name;
  newEmp->left=NULL;
  newEmp->right=NULL;
  return newEmp;
}
Node *Insert(Node* root, char name){
  if(root==NULL){ /*For empty tree */
    root= newEmployee(name);
    return root;
  }
  else{
    int check = Compare(*root, *name);
    if(check == 0 || check == 2){
      root->right=Insert(root->right,newEmployee);
      }
    else
      {root->left= Insert(root->left, newEmployee);}
    
  }
}

int Compare(char *r, char *n);{
  if(strcmp(*r, *n)==0) /* if name is the same */
    {  return 0;}
  else if(strcmp(*r, *n) > 0)/* if root is greater than new employee */
    {return 1;}
  else /* when root is smaller than employee */
    return 2;
 }
