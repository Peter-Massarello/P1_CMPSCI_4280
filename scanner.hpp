#ifndef SCAN_H
#define SCAN_H

#include "token.hpp"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <map>
#include <set>

const int state = 23;
const int columns = 25;

enum states {s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17, s18, s19, s20, s21, s22, s23, ERROR, FINAL, TBD, ID, DIGIT, EQUAL, DUBEQ, LESS};

extern map<char, int> columnMap;

extern states FSA_TABLE[state][columns];

extern set<string> keyWords;

vector<Token*> createTokenVector();

vector<Token*> createTokenVector(string fileName);

#endif