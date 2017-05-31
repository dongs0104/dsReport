//
//  StudentList.h
//  HW4-3
//
//  Created by Dong Shin on 2015. 6. 13..
//  Copyright (c) 2015년 Dong Shin. All rights reserved.
//

#ifndef _StudentList_H_
#define _StudentList_H_

#include <string>
#include <iostream>
#include "Iterator.h"
using namespace std;

class StudentList;//전방 선언

class Student
{
    friend class Iterator;
    friend class StudentList;
private:
    int id;
    string name;
    Student* prev;
    Student* next;
public:
    
    Student(){id = 0 ; name = "default" ; prev = next = this;}
    Student(int i, string n){id = i ; name = n ; prev = next = this;}
    
    Student* getPrev(){return prev;}
    Student* getNext(){return next;}

    int getId(){return id;}
    string getName(){return name;}
};

class StudentList
{
private:
    Student *head;
public:
    StudentList(){head = new Student();}
    
    Student* getFirst(){return head->next;}
    Student* getLast(){return head->prev;}
    Student* getHead(){return head;}
    void insertStudent(Student* s);
    void deleteStudent(int);
    
    void displayStudent();
    void displayReverse();
    void displayHeretoFrist(Student*);
    void displayHeretoLast(Student*);
    
    Student* findID();
};
#endif /* defined(_StudentList_H_) */