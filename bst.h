#include "bst.c"
#ifndef bst_included
#define bst_included

struct Node{
  String name;
  Node* left;
  Node* right;
}

  Node* rootNode; //stores address of root node
rootNode = NULL; //will set the empty tree as null
