//
//  TaskManager.h
//  HW4-3
//
//  Created by Dong Shin on 2015. 6. 13..
//  Copyright (c) 2015년 Dong Shin. All rights reserved.
//


#ifndef _TaskManager_H_
#define _TaskManager_H_

#include "StudentList.h"
#include "ioHandler.h"

using namespace std;

//DisplayOption is Defined on main.cpp
//1 is First to Last
//2 is Last to First
//3 is special ID to Last
//4 is Special ID to First
class TaskManager
{
public:
    TaskManager(){}
    ~TaskManager(){}
    
    void insertStudent(StudentList& sList);
    void removeStudent(StudentList& sList);
    void displayStudent(StudentList& sList);

    void displayOption1(StudentList& sList);
    void displayOption2(StudentList& sList);
    void displayOption3(StudentList& sList);
    void displayOption4(StudentList& sList);

};

#endif /* defined(_TaskManager_H_) */
