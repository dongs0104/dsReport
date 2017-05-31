//
//  Iterator.h
//  HW4-2
//
//  Created by Dong Shin on 2015. 6. 11..
//  Copyright (c) 2015년 Dong Shin. All rights reserved.
//

#ifndef HW4_2_Iterator_h
#define HW4_2_Iterator_h
#include "Polynomial.h"

class Term;
//반복자 선언
class Iterator{
public:
    Iterator(Term* startNode = 0){current = startNode;}
    Term& operator*() const;
    Term* operator->() const;
    //증가연산자 오버로딩(전위, 후위)
    Iterator& operator++();
    Iterator operator++(int);
    //비교연산자 오버로딩
    bool operator!=(const Iterator rhs)const;
    bool operator==(const Iterator rhs)const;
private:
    Term* current;
};
#endif
