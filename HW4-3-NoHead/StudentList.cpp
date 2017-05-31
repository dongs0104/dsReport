//
//  StudentList.cpp
//  HW4-3
//
//  Created by Dong Shin on 2015. 6. 13..
//  Copyright (c) 2015년 Dong Shin. All rights reserved.
//

#include "StudentList.h"

void StudentList::insertStudent(Student* s)
{
    if(!head)
    {
        head = new Student();
    }
    if (head->prev->id < s->id) {
        s->prev = head->prev;
        s->next = head;
        head->prev->next = s;
        head->prev = s;
        return;
    }
    else if (s->id < head->next-> id){
        s->prev = head;
        s->next = head->next;
        head->next->prev = s;
        head->next = s;
        return;
    }
    else
    {
        for (Iterator current = head ; ; ++current)
        {
            if (s->id < current->id) {
                s->next = current.getLink();
                s->prev = current ->prev;
                current->prev->next = s;
                current->prev = s;
                break;
            }
        }
    }
}

void StudentList::deleteStudent(Student* id)
{
    if (id){
        id->prev->next = id->next;
        id->next->prev = id->prev;
        delete id;
    }
}
void StudentList::displayStudent()
{
    for (Iterator current = getFirst(); current != head ; ++current)
    {
        cout << current->id << '\t' << current->name << endl;
    }
}
void StudentList::displayReverse()
{
    
    for (Iterator last = getLast() ; last != head ; --last) {
        cout << last->id << '\t' << last->name << endl;
    }
}
void StudentList::displayHeretoFrist(Student *id)
{
    if (id != NULL)
        for (Iterator current = id ; current != head ; --current) {
            cout << current->id << '\t' << current->name << endl;
        }
}
void StudentList::displayHeretoLast(Student *id)
{
    if (id != NULL)
        for (Iterator current = id; current != head; ++current) {
            cout << current->id << '\t' << current->name << endl;
        }
}
Student* StudentList::findID(){
    int id;
    cout << "학번을 입력하세요 : "; cin >> id;
    
    for (Iterator current = getFirst(); current != head ; ++current)
    {
        if (current->id == id) {
            return current.getLink();
        }
    }
    cout << "Not Data Found" << endl;
    return NULL;
}