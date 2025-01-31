	/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include <iostream>
#include "split.h"

int main(int argc, char* argv[]){
  int arr[5] = {0, 1, 17, 18, 20};
  Node* head = nullptr;
  Node* curr = head;
  for (int i=0; i<5; i++){
    if(i==0){
      head = new Node(arr[0], nullptr);
      curr = head; 
    } else {
      Node* newNode = new Node(arr[i], nullptr);
      curr->next = newNode;
      curr = newNode;	
    }
  }

	Node* odds = nullptr;
	Node* evens = nullptr;

	split(head, odds, evens);

  deleteList(head);
  head = nullptr;

  Node* tmpOdds = odds;
	Node* tmpEvens = evens;

  while(tmpOdds != nullptr){
    std::cout<<"Odd: "<< tmpOdds->value <<std::endl;
    tmpOdds = tmpOdds->next;
  }
  while(tmpEvens != nullptr){
    std::cout<<"Evens: "<< tmpEvens->value <<std::endl;
    tmpEvens = tmpEvens->next;
  }

	// while(odds != nullptr){
  //   Node* nextNode = odds->next;
  //   delete odds;
  //   odds = nextNode;
  // }
	// while(evens != nullptr){
  //   Node* nextNode = evens->next;
  //   delete evens;
  //   evens = nextNode;
  // }

  deleteList(odds);
  deleteList(evens);
}
