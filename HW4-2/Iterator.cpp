//
//  Iterator.cpp
//  HW4-2
//
//  Created by Dong Shin on 2015. 6. 11..
//  Copyright (c) 2015년 Dong Shin. All rights reserved.
//

#include "Iterator.h"

Term& Iterator::operator*() const{return *current;}
Term* Iterator::operator->() const{return current;}
Iterator& Iterator::operator++()
{
    current = current->link; return *this;
}
Iterator Iterator::operator++(int)
{
    Iterator old = *this;
    current = current->link;
    return old;
}
bool Iterator::operator!=(const Iterator rhs)const{
    return current !=rhs.current;
}
bool Iterator::operator==(const Iterator rhs)const{
    return current ==rhs.current;
}