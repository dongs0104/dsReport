//
//  Polynomial.cpp
//  HW4-2
//
//  Created by Dong Shin on 2015. 6. 11..
//  Copyright (c) 2015년 Dong Shin. All rights reserved.
//

#include "Polynomial.h"

using namespace std;
//Term Constructor
Term::Term()
{
    link = NULL;
    coef = 0 ;
    exp = 0 ;
}

Term::Term(float f, unsigned int ui)
{
    link = NULL;
    coef = f ;
    exp = ui ;
}
//Polynomial Constructor
Polynomial::Polynomial()
{
    head = last = new Term();
}

Polynomial::~Polynomial(){}

//Polynomial operator
void Polynomial::newTerm(const float f, const unsigned int e)
{
    last->link = new Term(f, e);
    last = last->link;
}
Polynomial Polynomial::operator +(const Polynomial &rhs)
{
    Polynomial tP;
    
    Iterator aPos = head->link;
    Iterator bPos = rhs.head->link;
    
    while(aPos != 0 && bPos != 0)
    {
        if (aPos->exp == bPos->exp)
        {
            float tF = aPos->coef + bPos->coef ;
            if (tF)
            {
                tP.newTerm(tF, aPos->exp);
            }
            aPos++; bPos++;
        }
        else if (aPos->exp < bPos->exp)
        {
            tP.newTerm(bPos->coef, bPos->exp);
            bPos = bPos->link;
        }
        else
        {
            tP.newTerm(aPos->coef, aPos->exp);
            aPos = aPos->link;
        }
    }
    
    for (; aPos != 0 ; aPos++)
    {
        tP.newTerm(aPos->coef, aPos->exp);
    }
    for (; bPos != 0 ; bPos++)
    {
        tP.newTerm(bPos->coef, bPos->exp);
    }
    return tP;
}


Polynomial Polynomial::operator *(const Polynomial &rhs)
{
    Polynomial sP;
    Iterator aPos = head->link;
    Iterator bPos = rhs.head->link;
    if(aPos != NULL && bPos != NULL) {
        for (; aPos != 0 ; ++aPos) {
            Polynomial tP;
            for (bPos = rhs.head->link; bPos != 0 ; ++bPos){
                tP.newTerm(aPos->coef * bPos->coef, aPos->exp + bPos->exp);
            }
            sP = sP + tP;
        }
    }
    else if (bPos == NULL) {
        return *this;
    }
    else {
        return rhs;
    }
    return sP;
}
//IoStream overloading
ostream& operator<< (ostream& os, const Polynomial &rhs)
{
    Term* markStart = rhs.head->getNext();
    Iterator current = markStart;
    
    for (; current != 0; ++current) {
        float _coef = current->getCoef();
        unsigned int _exp = current->getExp();
    
        if ( _coef != 0.0 ) {
            if (_coef != 0 && _coef != -1 && current != markStart)
                os << " + " ;
            
            if( _coef == -1)
                os << " - ";
            else if ( _coef != 1)
                os << _coef ;
            
            if( _exp == 1)
                os << "x";
            else if ( _exp != 0)
                os << "x^" << _exp ;
            else if ((_coef == 1 || _coef == -1 )&& _exp == 0)
                os << 1;
        }
        
    }
    
    return os;
}

istream& operator>>(istream &is, Polynomial &rhs)
{
    float tc = 0.0;
    unsigned int te = 0 ;
    static int count = 0;
    cout << ++count <<"번 째 다항식을 계수 - 지수 쌍으로 입력하세요.(지수가 0이면 입력 종료)" << endl;
    do
    {
        is >> tc >> te;
        if (tc == 0 && te == 0) {
            break;
        }
        rhs.newTerm(tc, te);
    } while (te != 0);
    
    return is;
}