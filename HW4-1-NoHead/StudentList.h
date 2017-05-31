//
//  StudentList.h
//  HW4-1
//
//  Created by Dong Shin on 2015. 6. 11..
//  Copyright (c) 2015년 Dong Shin. All rights reserved.
//

#ifndef _StudentList_H_
#define _StudentList_H_
#include <string>
#include <iostream>
using namespace std;

class StudentList;//전방 선언

class Student
{
    friend class StudentList;
private:
    int id;
    string name;
    Student* link;
public:
    
    Student(Student* next = NULL){id = 0 ; name = "default" ; link = next;}
    Student(int i, string n){id = i ; name = n ; link = NULL;}
    Student* getLink(){return link;}
    int getId(){return id;}
    string getName(){return name;}
};

class StudentList
{
private:
    Student *first;
public:
    StudentList(){first = NULL;}
    
    Student* getFirst(){return first;}
    
    void insertStudent(Student* s);
    void deleteStudent(int id);
    void displayStudent();
};
#endif /* defined(_StudentList_H_) */
