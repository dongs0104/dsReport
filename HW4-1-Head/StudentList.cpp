//
//  StudentList.cpp
//  HW4-1
//
//  Created by Dong Shin on 2015. 6. 11..
//  Copyright (c) 2015년 Dong Shin. All rights reserved.
//

#include "StudentList.h"

void StudentList::insertStudent(Student* s)
{
    Student* pre = NULL;
    
    for (Student* current = head; current ;pre = current, current = current->link)
    {
        if (s->id < current->id) {
            s->link = current;
            pre->link = s;
            break;
        }
        if(!current -> link){
            current->link = s;
            break;
        }
    }
}

void StudentList::deleteStudent(int id)
{
    
    Student* pre = head ;
    Student* current = pre->link;
    for (; current ;pre = current, current = current->link)
    {
        if (current->id == id) {
                Student* tempNode = current;
                pre->link = current->link;
                delete tempNode;
            break;
        }
    }
    if (current == NULL) {
        cout << "Not Found Data" << endl;
    }
}
void StudentList::displayStudent()
{
    for (Student* current = getFirst() ; current ; current = current->link)
    {
        cout << current->id << "\t" << current->name << endl;
    }
}