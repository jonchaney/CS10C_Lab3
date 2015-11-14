//
//  Node.h
//  Merge Sort
//
//  Created by Van Ralf Aguas on 10/25/15.
//  Copyright (c) 2015 Van Ralf Aguas. All rights reserved.
//

#ifndef __Merge_Sort__Node__
#define __Merge_Sort__Node__
#include <iostream>

template<class ItemType>
class Node
{
private:
    ItemType item;        // a data item
    Node<ItemType>* next; // pointer to next node
public:
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    ItemType getItem() const ;
    Node<ItemType>* getNext() const ;
    void mergeSort(Node<ItemType>*& head);
    Node<ItemType>* merge(Node<ItemType>*& head1, Node<ItemType>*& head2);
};
#endif
