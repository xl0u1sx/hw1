/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

// void deleteList(Node * list){
// 	Node * currElement = list;
// 	while(currElement != nullptr){
// 		Node * nextElement = currElement->next;
// 		delete currElement;
// 		currElement = nextElement;
// 	}
// }

void split(Node*& in, Node*& odds, Node*& evens){
  /* Add code here */
  // WRITE YOUR CODE HERE

  // create curr pointer for in
  // create curr pointer for odd, even 
  // Case 1: If current == nullptr
  //              1. set in to nullptr, return. 
  // Case 2: else
  //              1. if val%2 == 0 
  //              2. else                 
  // Reminder: Set in to nullptr, set head of odd and even

  // Node* Curr = in;
  // Node* eCurr = evens;
  // Node* oCurr = odds;

  if(in == nullptr){
    return;
  }
  Node* Next = in->next;
  Node* createNode = new Node(in->value, nullptr);
  if((in->value)%2 == 0){
    addEnd(evens, createNode);
    // if(evens == nullptr){
    //   evens = createNode;
    // } else {
    //   Node* eLast = evens; 
    //   while(eLast->next != nullptr){
    //     eLast = eLast->next;
    //   }
    //   eLast->next = createNode;
    // }
  } else {
    addEnd(odds, createNode);
    // if(odds == nullptr){
    //   odds = createNode;
    // } else {
    //   Node* oLast = odds; 
    //   while(oLast->next != nullptr){
    //     oLast = oLast->next;
    //   }
    //   oLast->next = createNode;
    // }
  }
  // Node* Next = in->next;
  // in->next = nullptr;
  // in = Next;
  delete in;
  in = nullptr;

  split(Next, odds, evens);

}

/* If you needed a helper function, write it here */

void addEnd(Node*& head, Node* point){
  if(head == nullptr){
    head = point;
    point->next = nullptr;
    return;
  }
  addEnd(head->next, point);
}