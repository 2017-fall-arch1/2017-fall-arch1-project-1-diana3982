#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

int main(){
  struct Node* root = NULL;/*empty tree is made */

  printf("Hello! Welcome to the Personnel Managment System.\n");

  int cont = 1;
  int ans;

  while(cont == 1){
    printf("\nPlease select a function you would like to perform:\n"
    "1: Add Employee\n"
    "2: Remove Employee\n"
    "3: Display Employee List\n");
    scanf(" %d", &ans);

    printf("%d\n",ans );

    if(ans == 1){
      char* name = "";
      printf("Please Enter Name of New Employee:\n");
      scanf(" %s",name);
      root = Insert(root, name);
      cont = 0;

    }
    else if(ans == 2){
      printf("We are Removing an Employee\n");

      cont = 0;
    }
    else if(ans == 3){
      printf("These are the Current Employees:\n");

      cont = 0;
    }
    else{
      printf("Invalid input try again...\n");

      cont = 0;
    }
}
  return 0;
}
