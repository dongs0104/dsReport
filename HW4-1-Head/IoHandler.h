//
//  IoHandler.h
//  HW4-1
//
//  Created by Dong Shin on 2015. 6. 11..
//  Copyright (c) 2015년 Dong Shin. All rights reserved.
//

#ifndef _IoHandler_H_
#define _IoHandler_H_

#include <iostream>
#include <string>
#include <fstream>
#include "TaskManager.h"
#include "StudentList.h"

using namespace std;

class IoHandler {
private:
    string fileName;
public:
    IoHandler(){fileName = "";}
    ~IoHandler(){}//명시적 선언
    
    void readFile(StudentList &s);
    void saveFile(StudentList & s);
    
    int getEvent();
    
    Student* getStudent();
};
#endif /* defined(_IoHandler_H_) */
