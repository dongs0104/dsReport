//
//  TaskManager.h
//  HW4-1
//
//  Created by Dong Shin on 2015. 6. 11..
//  Copyright (c) 2015년 Dong Shin. All rights reserved.
//


#ifndef _TaskManager_H_
#define _TaskManager_H_

#include "StudentList.h"
#include "ioHandler.h"
using namespace std;
class TaskManager
{
public:
    TaskManager(){}
    ~TaskManager(){}
    
    void insertStudent(StudentList& sList);
    void removeStudent(StudentList& sList);
    void displayStudent(StudentList& sList);
    
};

#endif /* defined(_TaskManager_H_) */
