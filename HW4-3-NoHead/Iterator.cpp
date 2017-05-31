//
//  Iterator.cpp
//  HW4-3
//
//  Created by Dong Shin on 2015. 6. 13..
//  Copyright (c) 2015년 Dong Shin. All rights reserved.
//

#include "Iterator.h"

Student* Iterator::getLink() const{return current;}
Student& Iterator::operator*() const{return *current;}
Student* Iterator::operator->() const{return current;}

Iterator& Iterator::operator++()
{
    current = current->next; return *this;
}
Iterator Iterator::operator++(int)
{
    Iterator old = *this;
    current = current->next;
    return old;
}

Iterator& Iterator::operator--()
{
    current = current->prev; return *this;
}
Iterator Iterator::operator--(int)
{
    Iterator old = *this;
    current = current->prev;
    return old;
}

bool Iterator::operator!=(const Iterator rhs)const
{
    return current != rhs.current;
}
bool Iterator::operator==(const Iterator rhs)const
{
    return current == rhs.current;
}