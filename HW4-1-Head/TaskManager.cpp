//
//  TaskManager.cpp
//  HW4-1
//
//  Created by Dong Shin on 2015. 6. 11..
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
    int id;
    cout << "삭제할 데이터의 학번-> "; cin >> id;
    sList.deleteStudent(id);
}
void TaskManager::displayStudent(StudentList& sList)
{
    sList.displayStudent();
}