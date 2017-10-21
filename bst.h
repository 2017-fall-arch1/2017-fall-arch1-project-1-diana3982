#ifndef bst_include
#define bst_include
//#include "bst.c"


typedef struct Node{
  char *name;
  struct Node* left;
  struct Node* right;
}Node;

struct Node* Insert(Node* root, char* name);

#endif

