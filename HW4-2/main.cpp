//
//  main.cpp
//  HW4-2
//
//  Created by Dong Shin on 2015. 6. 11..
//  Copyright (c) 2015년 Dong Shin. All rights reserved.
//
//  Display Polynomial Multiply
#include "Polynomial.h"

using namespace std;

int main ()
{
    //Declare variable
    Polynomial p1, p2, answer;
    
    cout << "곱할 두 다항식을 입력 받습니다."<< endl;
    
    //get Polynomial
    cin >> p1 >> p2;
    
    //operator *
    answer = p1 * p2;

    //Display Answer
    cout <<"( " << p1 << " ) *  ( " << p2 << " ) = "<< answer <<endl;
    
    return 0;
}//EndOfMain