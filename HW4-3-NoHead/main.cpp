//
//  main.cpp
//  HW4-3 NoHead
//
//  Created by Dong Shin on 2015. 6. 11..
//  Copyright (c) 2015년 Dong Shin. All rights reserved.
//

#include "IoHandler.h"

enum Menu { INSERT_STUDENT = 1, DELETE_STUDENT, DISPLAY_ALL_STUDENT, DISPLAY_REVERSE_STUDENT, DISPLAY_HTOE_STUDENT, DISPLAY_HTOF_STUDENT, EXIT }; //Specific To End, Front

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
            case DISPLAY_ALL_STUDENT:
                tm.displayOption1(sList);
                break;
            case DISPLAY_REVERSE_STUDENT:
                tm.displayOption2(sList);
                break;
            case DISPLAY_HTOE_STUDENT:
                tm.displayOption3(sList);
                break;
            case DISPLAY_HTOF_STUDENT:
                tm.displayOption4(sList);
                break;
        }
    }
    ioh.saveFile(sList);
    return 0;
}