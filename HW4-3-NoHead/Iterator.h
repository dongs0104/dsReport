//
//  Iterator.h
//  HW4-3
//
//  Created by Dong Shin on 2015. 6. 13..
//  Copyright (c) 2015년 Dong Shin. All rights reserved.
//

#ifndef __HW4_3__Iterator__
#define __HW4_3__Iterator__

#include "StudentList.h"
class Student;

class Iterator{
    
public:
    Iterator(Student* startNode = 0){current = startNode;}
    Student* getLink() const;
    Student& operator*() const;
    Student* operator->() const;
    //증감연산자 오버로딩(전위, 후위)
    Iterator& operator++();
    Iterator operator++(int);
    
    Iterator& operator--();
    Iterator operator--(int);
    
    //비교연산자 오버로딩
    bool operator!=(const Iterator rhs)const;
    bool operator==(const Iterator rhs)const;
private:
    Student* current;
};
#endif /* defined(__HW4_3__Iterator__) */
