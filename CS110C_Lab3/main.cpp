//
//  main.cpp
//  CS110C_Lab3
//
//  Created by Jon Chaney on 10/26/15.
//  Copyright © 2015 Jon Chaney. All rights reserved.
//

#include <sstream>
#include <string>
#include <iostream>
#include "Node.cpp"
using namespace std;

int main()
{
  stringstream ss;
  int item;
  string input;
  
  // get numbers to be sorted
  cout << "Enter numbers to be sorted: ";
  getline(cin, input);
  ss << input;
  
  // add items to linked list
  Node<int> *head = nullptr;  // points to head of list
  while(ss >> item)
  {
    Node<int> *ptr = new Node<int>(item);
    ptr->setNext(head);
    head = ptr;
  }
  
  // sort list
  head->mergeSort(head);
  
  // print linked list
  cout << "Sorted numbers: ";
  for(Node<int> *curPtr = head;
      curPtr != nullptr;
      curPtr = curPtr->getNext())
        cout << curPtr->getItem() << " ";
  
  // set all pointers to null in linked list
  Node<int>* curPtr = head->getNext();
  while(curPtr != nullptr)
  {
    head->setNext(nullptr);
    head = curPtr;
    curPtr = curPtr->getNext();
  }
  
  delete curPtr;
  curPtr = nullptr;
  delete head;
  head = nullptr;
  
  ss.clear();
  
  return 0;
}





