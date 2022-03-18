/*******************************************************************
YOU ARE NOT ALLOWED TO MODIFY THE STRUCT AND THE FUNCTION PROTOTYPES
*******************************************************************/

/******************************
Group 6:
TOLENTINO, John Enrico
CRUZ, Arion John
HERNANDEZ, Pierre Vincent
******************************/


#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *pLeft;
    struct Node *pRight;
};

typedef struct Node sNode;

typedef struct {
	sNode *pRoot;
} bst;

bst* create() {
	return (bst*)malloc(sizeof(bst));
}

void insert(bst *t, int x) {
	// care of Pierre Hernandez

  sNode *tmp = t->pRoot, *parent = NULL;

  // DEBUGGING PURPOSES
  /*
  if(tmp == NULL)
    printf("No root node yet\n\n");
  */

  // continues to move the pointer until it reaches an
  // empty node
  while(tmp != NULL)
  {
    // get the address of the parent node as basis
    parent = tmp;

    // value x is greater than the data of the current node
    if(x > tmp->data)
      tmp = tmp->pRight; // move to the right child node

    // value x is less than the data of the current node
    else if(x < tmp->data)
      tmp = tmp->pLeft; // move to the left child node
  }
  
  // creates new node where the x value will be stored
  // and this node will be attached to the tree
  tmp = (sNode*)malloc(sizeof(sNode));
  tmp->data = x;
  tmp->pRight = NULL;
  tmp->pLeft = NULL;

  // if there is no root node yet in the tree
  if(parent == NULL)
  {
    t->pRoot = tmp;

    // DEBUGGING PURPOSES
    /*
    printf("Created Root node: %d\n\n", t->pRoot->data);
    */
  }

  // attach as the right node of the current parent node
  else if(x > parent->data)
  {
    parent->pRight = tmp;

    // DEBUGGING PURPOSES
    /*
    printf("Current node: %d\n", parent->data);
    printf("Inserted on the right: %d\n\n", parent->pRight->data);
    */
  }
    
  // attach as the left node of the current parent node
  else if(x < parent->data)
  {
    parent->pLeft = tmp;

    // DEBUGGING PURPOSES
    /*
    printf("Current node: %d\n", parent->data);
    printf("Inserted on the left: %d\n\n", parent->pLeft->data);
    */
  }

}

sNode* search(bst *t, int x) {
	// care of Pierre Hernandez
  
  sNode *tmp = t->pRoot;

  /*
    Continuously move down the tree until node->data == x
    or until it passed the last branch of its search path,
    which means that x is non-existent in t
  */
  while(tmp != NULL && tmp->data != x)
  {
    // x is less than the current node
    // continue to search on the left node
    if(x < tmp->data)
      tmp = tmp->pLeft;

    // x is greater than the current node
    // continue to search on the right node
    else if(x > tmp->data)
      tmp = tmp->pRight;
  }

  // either x is non-existent in t or exists in t
  return tmp;
}

void inorder(sNode *pPointer) {
	// care of Airon Cruz
  
  if(pPointer != NULL)
  {
    //traverse on the left children node of the current node until it reaches a leaf
    inorder(pPointer->pLeft);
    //print the stored data of the node
    printf("%d ", pPointer->data);
    //traverse on the right children node of the current node until it reachees a leaf
    inorder(pPointer->pRight);

  }
}

void preorder(sNode *pPointer) {
	// care of Pierre Hernandez

  // checks if it is an empty tree
  if(pPointer != NULL)
  {
    // print the data of current node
    printf("%d ", pPointer->data);
    // traverse on the left children node of current node
    preorder(pPointer->pLeft);
    // traverse on the right children node of current node
    preorder(pPointer->pRight);
  }
}

void postorder(sNode *pPointer) {
	// care of Enrico Tolentino

  //determiens if tree is empty
  if(pPointer != NULL){

    //traverses to the left children node from the current node
    postorder(pPointer -> pLeft);

    //prints data of the current node
    postorder(pPointer -> pRight);

    //traverses to the right children node from the current node
    printf("%d ", pPointer -> data);

  }

}

sNode* maximum(sNode *pPointer) {
	// care of Airon Cruz

    //search for the right most node or leaf (no child) node
    sNode *temp = pPointer;
    
    //while the pPointer's right node is not equal to NULL continue to pass the pointer to its right node
    while(temp->pRight != NULL)
        temp = temp->pRight;
        
    //for checking only (to be deleted once checked already) ----->UPDATE: WORKING !
  //  printf("\nMAX VALUE: %d\n", temp->data);
    return temp;

}

sNode* minimum(sNode *pPointer) {
	// care of Airon Cruz
  
  
  sNode *temp = pPointer;

  //while the pPointer's left node is not equal to NULL continue to pass the pointer to its left node
  while(temp->pLeft != NULL)
    temp = temp->pLeft;
  
  //for checking only
 // printf("\nMINIMUM VALUE : %d\n", temp->data);

  return temp;

}

sNode* parent(bst *t, int x) {
	// care of Pierre Hernandez
  
  sNode *tmp = t->pRoot, *parent = NULL;
  
  /*
    Continuously move down the tree until node->data == x
    or until it passed the last branch of its search path,
    which means that x is non-existent in t
  */
  while(tmp != NULL && tmp->data != x)
  {
    // get the address of the parent as basis
    parent = tmp;

    // value x is greater than the data of the current node
    if(x > tmp->data)
      tmp = tmp->pRight; // move to the right node

    // value x is less than the data of the current node
    else if(x < tmp->data)
      tmp = tmp->pLeft; // move to the left node
  }

  // x is non-existent in t
  if(tmp == NULL)
    return tmp;  
  
  // x exists in t
  return parent;
  
}

sNode* successor(bst *t, int x) {
	// care of Enrico Tolentino
  
  sNode *key = search(t,x);

  sNode *ancestor = NULL;

  if(key != NULL && key -> pRight != NULL){
    // returns the minimum of the right subtree of the key
    return minimum(key -> pRight);

  }else if(key != NULL) {
    
    ancestor = parent(t, key -> data);
    
    while(ancestor != NULL && 
      (ancestor->pLeft == NULL || 
        ancestor->pLeft->data != key->data))
    {
      key = ancestor;
      ancestor = parent(t, ancestor -> data);
    }


  }
  // returns the ancestor of the key with a left subtree
  // that is also an ancestor of the key
  return ancestor;

}

sNode* predecessor(bst *t, int x) {
	// care of Enrico Tolentino

  sNode *key = search(t,x);
  sNode *ancestor = NULL;

  if(key != NULL && key -> pLeft != NULL){
    // returns the maximum of the left subtree of the key
    return maximum(key -> pLeft);

  }else if(key != NULL) {

    ancestor = parent(t, key -> data);
    
    while(ancestor != NULL && 
      (ancestor->pRight == NULL || 
        ancestor->pRight->data != key->data))
    {
      key = ancestor;
      ancestor = parent(t, ancestor -> data);
    }

  }
  // returns the ancestor of the key with a right subtree
  // that is also an ancestor of the key
  return ancestor;
  

}
