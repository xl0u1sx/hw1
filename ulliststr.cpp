#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr(){
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr(){
  clear();
}

bool ULListStr::empty() const{
  return size_ == 0;
}

size_t ULListStr::size() const{
  return size_;
}

// WRITE YOUR CODE HERE

// push_back
void ULListStr::push_back(const std::string& valIn){
  if(empty() == true){
    // if list is empty
    Item* newNode = new Item();
    newNode->val[newNode->last] = valIn; // at the start of val
    (newNode->last)++;
    head_ = newNode;
    tail_ = newNode;
    size_++; 
    return;
  } else if(tail_->last >= ARRSIZE){
    //tail_ is full
    Item* newNode = new Item();
    tail_->next = newNode;
    newNode->prev = tail_;
    tail_ = newNode;
    //add value in new Node
    tail_->last = 1; 
    tail_->first = 0;
    tail_->val[tail_->first] = valIn; 
    size_++; 
    return;	
  }
  // if node not full
  tail_->val[tail_->last] = valIn; 
  tail_->last = tail_->last +1; 
  size_ = size_+1; 
  return;
}

// pop_back
void ULListStr::pop_back(){
  if(tail_->last <= 1){
    //check if the value is the last one in Node
    Item* tmp = tail_;
    size_ = size_-1; 
    if(tail_->prev != nullptr){
      //if it's not the only node
      tail_ = tail_->prev; 
      tail_->next = nullptr;
    } else {
      //if it's the only node
      head_ = nullptr;
      tail_ = nullptr;
    }
    delete tmp; 
    return;
  }
  //if it's not the last one in node, delete the value
  // tail_->val[tail_->last] = NULL; 
  tail_->last = (tail_->last)-1;
  size_ = size_-1; 
  return; 
}

//push_front
void ULListStr::push_front(const std::string& valIn){
  if(empty() == true){
    // if list is empty
    Item* newNode = new Item(); 
    head_ = newNode;
    tail_ = newNode;
    head_->last = ARRSIZE;
    head_->first = ARRSIZE-1;
    head_->val[head_->first] = valIn; 
    size_ = size_+1; 
    return;
  }else if(head_->first <= 0){ 
    //head_ node is full, add newNode
    Item* newNode = new Item(); 
    head_->prev = newNode; 
    newNode->next = head_;
    head_ = newNode; 
    head_->last = ARRSIZE;
    head_->first = ARRSIZE-1;
    head_->val[head_->first] = valIn; 
    size_ = size_+1; 
    return;
  }
  //if it's not full then add value in front in the current node
  head_->first = (head_->first)-1;
  head_->val[head_->first] = valIn; 
  //increment size_
  size_ = size_+1; 
  return; 
}

//pop_front
void ULListStr::pop_front(){
  if((head_->last - head_->first) <= 1){
    //check if the front value is the last val in Node
    Item* tmp = head_; 
    size_ = size_-1; 
    if(head_->next != nullptr){
      // if the node is not the only node
      head_ = head_->next;
      head_->prev = nullptr;
    } else {
      // if the node is the only node
      head_ = nullptr;
      tail_ = nullptr;
    }
    delete tmp; 
    return;
  }
  //if its not the last val then simply delete a val
  // head_->val[head_->first] = NULL; 
  head_->first = head_->first +1;
  //decrement size_
  size_ = size_-1; 
  return; 
}

// back
std::string const & ULListStr::back() const{
  //use tail_ pointer 
  return tail_->val[tail_->last -1]; 
}

//front
std::string const & ULListStr::front() const{
  //use head_ pointer
  return head_->val[head_->first]; 
}

//getValAtLoc
std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(loc>size_){return nullptr;}
  Item* curr = head_;
  while(curr != nullptr){
    for(size_t i=(curr->first); i<(curr->last); i++){
      if(loc!=0){
        loc = loc-1;
      } else {
        return & curr->val[i];
      }
    }
    curr = curr->next;
  }
  return nullptr;
}

void ULListStr::set(size_t loc, const std::string& val){
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc){
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear(){
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
