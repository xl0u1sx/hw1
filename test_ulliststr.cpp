#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[]){
  ULListStr list; 

  list.push_back("Str1");
  std::cout << "push_back once: " << std::endl;
  for(size_t i=0; i<list.size(); i++){
    std::cout << list.get(i) << std::endl;
  }

  list.push_back("Str2");
  std::cout << "push_back twice: " << std::endl;
  for(size_t i=0; i<list.size(); i++){
    std::cout << list.get(i) << std::endl;
  }

  list.pop_back();
  std::cout << "pop_back once: " << std::endl;
  for(size_t i=0; i<list.size(); i++){
    std::cout << list.get(i) << std::endl;
  }

  list.pop_back();
  std::cout << "pop_back twice." << std::endl;
  // for(size_t i=0; i<list.size(); i++){
  //   std::cout << list.get(i) << std::endl;
  // }

  list.push_front("Str3");
  std::cout << "push_front once: " << std::endl;
  for(size_t i=0; i<list.size(); i++){
    std::cout << list.get(i) << std::endl;
  }

  list.push_front("Str4");
  std::cout << "push_front twice: " << std::endl;
  for(size_t i=0; i<list.size(); i++){
    std::cout << list.get(i) << std::endl;
  }

  list.pop_front();
  std::cout << "pop_front once: " << std::endl;
  for(size_t i=0; i<list.size(); i++){
    std::cout << list.get(i) << std::endl;
  }

  list.pop_front();
  std::cout << "pop_front twice." << std::endl;
  // for(size_t i=0; i<list.size(); i++){
  //   std::cout << list.get(i) << std::endl;
  // }

  return 0;
}
			