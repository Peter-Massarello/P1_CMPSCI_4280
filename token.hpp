/*
Name: Peter Massarello
Instructor: Mark Hauschild
Assignment: P1
Date: September 20th 2021
Class: CMPSCI 4280
*/
#ifndef TOKEN_H
#define TOKEN_H

#include <vector>
#include <string>
using namespace std;

// Struct for Token
struct Token {
    string token;
    string tokenType;
    int lineNum;
    int charNum;
};

#endif