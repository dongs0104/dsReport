//
//  Polynomial.h
//  HW4-2
//
//  Created by Dong Shin on 2015. 6. 11..
//  Copyright (c) 2015년 Dong Shin. All rights reserved.
//

#ifndef __P__Polynomial__
#define __P__Polynomial__

#include <iostream>
#include "Iterator.h"
using namespace std;


class Polynomial;//전방참조

class Term
{
    friend class Polynomial;
    friend class Iterator;
private:
    float coef; //계수
    unsigned int exp; //지수
    Term* link;
public:
    float getCoef(){return coef;}//출력 연산을 위해
    unsigned int getExp(){return exp;}//출력 연산을 위해 만들었음.
    Term* getNext(){return link;}//다음번째(링크)를 반환
    //생성자
    Term();
    Term(float, unsigned int);
};

class Polynomial
{
private:
    //p77, ADT2.3의 설명에 따라 계수는 float 지수는 음이아닌 정수의 지수 사용.
    Term *head;
    Term *last;
public:
    
    Polynomial();
    ~Polynomial();
    //값을 넣어주는 연산자
    void newTerm(float f, unsigned int e);
    //연산자 오버로딩
    Polynomial operator + (const Polynomial &rhs);
    Polynomial operator * (const Polynomial &rhs);
    //출력 연산자 오버로딩
    friend ostream& operator<< (ostream& os, const Polynomial &rhs);
    //입력 연산자 오버로딩
    friend istream& operator>>(istream &is, Polynomial &rhs);
};


#endif /* defined(__P__Polynomial__) */
