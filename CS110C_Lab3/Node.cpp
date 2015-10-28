//
//  Node.cpp
//  Merge Sort
//
//  Created by Van Ralf Aguas on 10/25/15.
//  Copyright (c) 2015 Van Ralf Aguas. All rights reserved.
//

#include "Node.h" 
#include <iostream>

template<class ItemType> Node<ItemType>::Node() : next(nullptr)
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
//             that were in the original linked list, but in sorted order
template<class ItemType>
void mergeSort( Node<ItemType>*& head);

// returns a pointer to a sorted linked list that results from merging the sorted
// linked lists pointed to by head1 and head2
// pre  : head1 and head2 point to sorted linked lists
// post : returns a pointer to a sorted linked list containing the nodes
//        that used to be in the sorted linked lists pointed to by head1 and head2;
//        head1 and head2 have the value nullptr
template<class ItemType>
Node<ItemType>* merge(Node<ItemType>*& head1,
                      Node<ItemType>*& head2);

