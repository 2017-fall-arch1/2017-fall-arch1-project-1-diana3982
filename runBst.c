#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

void insertPerson(Node* root, String name);

int main(){

  Node* root = NULL;//creates the empty tree
  insertPerson(root, "Diana Juarez");
  printf("Hello I ran\n");
}
