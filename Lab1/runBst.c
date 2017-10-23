#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

int main(){
  struct Node* root = NULL;/*empty tree is made */

  printf("Hello! Welcome to the Personnel Managment System.\n");

  int cont = 1;
  int ans;
  char* name = "";

  while(cont == 1){
    printf("\nPlease select a function you would like to perform:\n"
    "1: Add Employee\n"
    "2: Remove Employee\n"
    "3: Display Employee List\n");
    scanf(" %d", &ans);

    if(ans == 1){
      char name[] = "";/* strings store as char arrays*/
      printf("Please Enter Name of New Employee:\n");
      scanf(" %s",name);
      root = Insert(root, name);

      printf("\nWould you like to \n"
      "1: Continue or \n"
      "0: Exit System?\n");
      scanf("%d", &cont);
    }
    else if(ans == 2){
      printf("We are Removing an Employee\n");
      printf("Please Enter Name of the Employee to Remove:\n");
      scanf(" %s",name);
      root = Delete(root, name);

      printf("\nWould you like to \n"
      "1: Continue or \n"
      "0: Exit System?\n");
      scanf("%d", &cont);
    }
    else if(ans == 3){
      printf("These are the Current Employees:\n");
      Traverse(root);

      printf("\nWould you like to \n"
      "1: Continue or \n"
      "0: Exit System?\n");
      scanf("%d", &cont);
    }
    else{
      printf("Invalid input try again...\n");
    }
}
  printf("Goodbye! :-)");
  return 0;
}
