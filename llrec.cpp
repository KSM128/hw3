#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){

  // base case: no more items
  if(!head){
    smaller = nullptr;
    larger = nullptr;
    return;
  }

  // store current head for later recursion
  Node* curr = head;
  head = head->next;
  curr->next = nullptr;

  // process current node
  if(curr->val <= pivot){
    smaller = curr;
    llpivot(head, smaller->next, larger, pivot);
  } else {
    larger = curr;
    llpivot(head, smaller, larger->next, pivot);
  }
}
