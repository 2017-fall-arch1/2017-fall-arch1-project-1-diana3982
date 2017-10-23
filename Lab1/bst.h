#ifndef bst_include
#define bst_include

struct Node* NewEmployee(char* name);
struct Node* Insert(struct Node* root, char* name);
struct Node* Delete(struct Node* root, char* name);
void Traverse(struct Node* root);

#endif
