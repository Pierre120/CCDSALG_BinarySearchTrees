#include <stdio.h>
#include "bst.h"

int main(void) 
{
  // tree to be used for all test
  bst *t = create();

  // data to be inserted
  int nData[] = {  25, 20, 18, 23, 36, 2001, -11, 45, 30, 34, 28, 40, 38};



  // number of elements nData has
  int size = (int)sizeof(nData) / 4;

  // receives the return value of sNode* functions
  sNode* s;

  /*
    !!! BE SURE THAT THE INSERT PART IS UNCOMMENTED
        TO MAKE YOUR LIVES EASIER WHEN INSERTING DATA.
        JUST MANIPULATE THE ELEMENTS OF nData.
  */


  // ----- bst* create() function -----
  /*
    // STATUS: TESTED & WORKING
    // -- INSERT TEST CASE HERE --

    if(t == NULL)
    {
      printf("No Tree created yet.\nCreating tree\n\n");
      t = create();
    }
    
    printf("There is an existing tree now.\n");
    printf("Address of tree: %p\n\n", t);
    
    free(t);

  */


  // ----- void insert() function -----
  ///*
    // STATUS: TESTED & WORKING
    // -- INSERT TEST CASE HERE --
    
    for(int n = 0; n < size; n++)
      insert(t, nData[n]);
    
    //free(t);
  //*/


  // ----- sNode* search() function -----
  ///*
    // STATUS: TESTED & WORKING
    // -- INSERT TEST CASE HERE --
    
    // !!!! MAKE SURE TO UNCOMMENT THE INSERT PART
    int samplenum = 20;
    printf("Searching %d in Binary Search Tree...\n", samplenum);

    s = search(t, samplenum);

    if(s != NULL)
    {
      printf("Found %d in...\n", samplenum);
      printf("Current node: %d\n", s->data);

      if(s->pLeft != NULL)
        printf("Left node: %d\n", s->pLeft->data);

      if(s->pRight != NULL)
        printf("Right node: %d\n", s->pRight->data);
    }
    else
      printf("Not found.\n");

  //*/


  // ----- void inorder() function -----
  ///*
    // STATUS: TESTED & WORKING
    // -- INSERT TEST CASE HERE --
    printf("\nInorder:\n");
    inorder(t->pRoot);
    printf("\n");
  //*/


  // ----- void preorder() function -----
  ///*
    // STATUS: TESTED & WORKING
    // -- INSERT TEST CASE HERE --

    printf("\nPreorder:\n");
    preorder(t->pRoot);
    printf("\n");

  //*/


  // ----- void postorder() function -----
  ///*
    // STATUS: TESTED & WORKING
    // -- INSERT TEST CASE HERE --
    printf("\nPostorder:\n");
    //code does not run  starting from here if param for val in successor is the largest
    // Pierre: it seems that the postorder() is working
    postorder(t -> pRoot);
    printf("\n");
  //*/
  
  

  // ----- sNode* maximum() function -----
  ///*
    // STATUS: TESTED & WORKING
    // -- INSERT TEST CASE HERE --
    s = maximum(t->pRoot);   //working already
    printf("Max: %d\n", s->data);
  //*/
    


  // ----- sNode* minimum() function -----
  ///*
    // STATUS: TESTED & WORKING
    // -- INSERT TEST CASE HERE --
    s = minimum(t->pRoot);   //working already
    printf("Min: %d\n", s->data);
  //*/

  


  // ----- sNode* parent() function -----
  /*
    // STATUS: TESTED & WORKING
    // -- INSERT TEST CASE HERE --

    int nVal = 20;
    s = parent(t, nVal);

    if(s != NULL)
    {
      printf("Parent node of %d: %d\n", nVal, s->data);

      if(s->pLeft != NULL)
        printf("Left node of parent node: %d\n", s->pLeft->data);

      if(s->pRight != NULL)
        printf("Right node of parent node: %d\n", s->pRight->data);
    }
    else
      printf("%d doesn't have a parent\nor %d doesn't exist in the tree\n", nVal, nVal);

  */

  sNode *a, *b; // for successor and predecessor
  int val = -11; // ''

  // ----- sNode* successor() function -----
  /*
    // STATUS: TESTED & WORKING
    // -- INSERT TEST CASE HERE --
    a = successor(t, val);

    if(a != NULL){
      printf("\n\nsuccessor: %d\n", a -> data);
    }else{
      printf("no successor for %d\n", val);
    }
  */

  // ----- sNode* predecessor() function -----
  /*
    // STATUS: TESTED & WORKING
    // -- INSERT TEST CASE HERE --
    b = predecessor(t, val);

    if(b != NULL){
      printf("\n\npredecessor: %d\n", b -> data);
    }else{
      printf("no predecessor for %d\n", val);
    }
  */

  
 

  return 0;
}