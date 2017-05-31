//
//  IoHandler.cpp
//  HW4-1
//
//  Created by Dong Shin on 2015. 6. 11..
//  Copyright (c) 2015년 Dong Shin. All rights reserved.
//

#include "IoHandler.h"

int IoHandler::getEvent()
{
    int menu;
    cout << "==========================================" << endl;
    cout << "1.새 학생 입력" << endl;
    cout << "2.학생 삭제" << endl;
    cout << "3.학번 순으로 전체 출력" << endl;
    cout << "4.종료" << endl;
    cout <<"==========================================" << endl;
    cin >> menu;
    
    return menu;
}
void IoHandler::readFile(StudentList &sl)
{
    ifstream fin; string file; //FOR FILE OPEN
    
    cout <<"학생의 이름과 학번이 저장된 파일을 입력하세요 : ";
    cin >> file;
    
    fileName = file;
    
    fin.open(fileName, ios_base::in);
    
    if (!fin.is_open())
        throw "Can not found" + fileName ;
    
    int id; string name; //DEFINE STUDENT INFO
    
    while(!fin.eof())
    {
        fin >> id >> name;
        Student* s = new Student(id,name);
        sl.insertStudent(s);
    }
    fin.close();
}
void IoHandler::saveFile(StudentList & s)
{
    ofstream fout;
    fout.open(fileName, ios_base::out);
    if (!fout.is_open())
        throw "Can not found" + fileName ;
    for (Student * current = s.getFirst(); current ; current =  current->getLink()) {
        fout << endl << current->getId() << "\t" << current->getName() ;
    }
    fout.close();
}
Student* IoHandler::getStudent()
{
    int id;
    string name;
    
    cout << "학번 -> "; cin >> id;
    cout << "이름 -> "; cin >> name;
    Student* s = new Student(id, name);

    return s;
}