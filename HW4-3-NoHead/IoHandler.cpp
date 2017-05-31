//
//  IoHandler.cpp
//  HW4-3
//
//  Created by Dong Shin on 2015. 6. 13..
//  Copyright (c) 2015년 Dong Shin. All rights reserved.
//

#include "IoHandler.h"

int IoHandler::getEvent()
{
    int menu;
    cout << "=========================================="<< endl;
    cout << "1.새 학생 입력" << endl;
    cout << "2.학생 삭제" << endl;
    cout << "3.학번 순으로 전체 출력" << endl;
    cout << "4.학번 역순으로 전체 출력" <<endl;
    cout << "5.특정 학번부터 전체 출력" <<endl;
    cout << "6.특정 학번부터 첫 학생까지 역순 출력"<<endl;
    cout << "7.종료" << endl;
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
    
    while(1)
    {
        fin >> id >> name;
        if (fin.eof())
            break;
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
    for (Iterator current = s.getFirst(); current != s.getHead() ; ++current) {
        fout << current -> getId() << '\t' << current -> getName() << endl;
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