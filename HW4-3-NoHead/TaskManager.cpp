//
//  TaskManager.cpp
//  HW4-3
//
//  Created by Dong Shin on 2015. 6. 13..
//  Copyright (c) 2015년 Dong Shin. All rights reserved.
//

#include "TaskManager.h"

void TaskManager::insertStudent(StudentList& sList)
{
    IoHandler ioh;
    Student* s = ioh.getStudent();
    sList.insertStudent(s);
}
void TaskManager::removeStudent(StudentList& sList)
{
    sList.deleteStudent(sList.findID());
}

void TaskManager::displayOption1(StudentList &sList)
{
    sList.displayStudent();
}
void TaskManager::displayOption2(StudentList &sList)
{
    sList.displayReverse();
}
void TaskManager::displayOption3(StudentList &sList)
{
    sList.displayHeretoLast(sList.findID());
}
void TaskManager::displayOption4(StudentList &sList)
{
    sList.displayHeretoFrist(sList.findID());
}