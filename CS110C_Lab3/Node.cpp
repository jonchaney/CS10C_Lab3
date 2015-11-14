//
//  Node.cpp
//  Merge Sort
//
//  Created by Van Ralf Aguas on 10/25/15.
//  Copyright (c) 2015 Van Ralf Aguas. All rights reserved.
//

#include <iostream>
#include "Node.h"
using namespace std;

template<class ItemType>
Node<ItemType>::Node() : next(nullptr)
{}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr)
{}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) :
item(anItem), next(nextNodePtr)
{}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
  item = anItem;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
  next = nextNodePtr;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
  return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
  return next;
}

// sorts the link list pointed to by head
// pre  : head points to a linked list of items
// post : head points to a sorted linked list, containing the items
//        that were in the original linked list, but in sorted order
template<class ItemType>
void Node<ItemType>::mergeSort(Node<ItemType>*& head)
{
  Node<int>* head1 = head;      // head of sublist one
  Node<int>* head2 = nullptr;   // head of sublist two
  
  // base case (if list is empty or list is one item stop recursion)
  if ((head == nullptr) || (head->next == nullptr))
  {
    return;
  }
  
  // spilt list into two sublists
  Node<int> *frontLast = nullptr; // last item in sublist a
  Node<int> *p1 = head;           // iterates through each item in list
  Node<int> *p2 = head;           // iterates two nodes at a time
  
  while (p2) {
    frontLast = p1;
    p1 = p1->next;
    // test if p2 is null
    p2 = p2->next ? p2->next->next : nullptr;
  }
  
  frontLast->next = nullptr;  // disconnect sublists
  head2 = p1;                 // head of second sublist
  
  // recursive call
  mergeSort(head1);
  mergeSort(head2);
  
  // merge and sort sublists
  head = merge(head1, head2);
  
  // set all pointers to null
  frontLast = nullptr;
  p1 = nullptr;
  p2 = nullptr;
  head1 = nullptr;
  head2 = nullptr;
}

// returns a pointer to a sorted linked list that results from merging the sorted
// linked lists pointed to by head1 and head2
// pre  : head1 and head2 point to sorted linked lists
// post : returns a pointer to a sorted linked list containing the nodes
//        that used to be in the sorted linked lists pointed to by head1 and head2;
//        head1 and head2 have the value nullptr
template<class ItemType>
Node<ItemType>* Node<ItemType>::merge(Node<ItemType>*& head1,Node<ItemType>*& head2)
{
  Node<int>* result = nullptr;
  
  // base case
  if (head1 == nullptr)
    return head2;
  else if (head2 == nullptr)
    return head1;

  // test for size of data item
  if (head1->item <= head2->item)
  {
    // pointer to sublist a
    result = head1;
    // recursive call
    result->next = merge(head1->next, head2);
  }
  else
  {
    // pointer to sublist b
    result = head2;
    // recursive call
    result->next = merge(head1, head2->next);
  }
  
  // return sorted list
  return result;
}


