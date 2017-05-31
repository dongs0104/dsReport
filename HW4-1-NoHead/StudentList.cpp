//
//  StudentList.cpp
//  HW4-1
//
//  Created by Dong Shin on 2015. 6. 11..
//  Copyright (c) 2015년 Dong Shin. All rights reserved.
//

#include "StudentList.h"

void StudentList::insertStudent(Student* newStudent)
{
    Student* current = first ;
    Student* pre = NULL ;
    if (!first) {
        first = newStudent;
    }
    else {
        for (; current ; pre = current, current = current->link)
        {
            if (newStudent->id < current->id) {
                newStudent->link = current;
                if (first == current) {
                    first = newStudent;
                }
                else {
                    pre->link = current;
                }
                break;
            }
            if (!current->link) {
                current->link = newStudent;
                break;
            }
        }
    }
}
void StudentList::deleteStudent(int id)
{
    Student* x = frist ;
    Student* pre = NULL ;
    if (!frist)
        throw "Empty List";
    for (; x ;pre = x, x = x->link)
    {
        if (x->id == id) {
            if (frist == x) {
                Student* tempNode = x;
                frist = x->link;
                delete tempNode;
            }
            else
            {
                Student* tempNode = x;
                pre->link = x->link;
                delete tempNode;
            }
            break;
        }
    }
    if (!x) {
        cout << "Not Found Data" << endl;
    }
}
void StudentList::displayStudent()
{
    for (Student* x = frist ; x ; x = x->link)
    {
        cout << x->id << "\t" << x->name << endl;
    }
}