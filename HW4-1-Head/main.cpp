//
//  main.cpp
//  HW4-1
//
//  Created by Dong Shin on 2015. 6. 11..
//  Copyright (c) 2015년 Dong Shin. All rights reserved.
//

#include "IoHandler.h"

enum Menu { INSERT_STUDENT = 1, DELETE_STUDENT, DISPLAY_STUDENT, EXIT };

int main()
{
    IoHandler ioh;
    StudentList sList;
    TaskManager tm;
    //Load From File
    ioh.readFile(sList);
    while(1)
    {
        int menu = ioh.getEvent();
        if (menu == EXIT) // EXIT CONDITION
            break;
        switch(menu)
        {
            case INSERT_STUDENT:
                tm.insertStudent(sList);
                break;
            case DELETE_STUDENT:
                tm.removeStudent(sList);
                break;
            case DISPLAY_STUDENT:
                tm.displayStudent(sList);
                break;
        }
    }
    ioh.saveFile(sList);
    return 0;
}