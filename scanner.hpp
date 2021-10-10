#ifndef SCAN_H
#define SCAN_H

#include "token.hpp"
#include <iostream>
#include <stdio.h>

const int state = 23;
const int columns = 25;

enum states {s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17, s18, s19, s20, s21, s22, s23, ERROR, FINAL, TBD};

states FSA_TABLE[state][columns] = {
//        a-z     A-Z     0-9     _       $       =       <       >       :       +       -       *       /       %       .       (       )       ,       {       }       ;       [       ]     WS     EOF
/* s1  */ {s2,    ERROR,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  s1,    FINAL},
/* s2  */ {s2,    s2,     s2,     s2,     FINAL,  FINAL,  FINAL,  FINAL,  FINAL,  FINAL,  FINAL,  FINAL,  FINAL,  FINAL,  FINAL,  FINAL,  FINAL,  FINAL,  FINAL,  FINAL,  FINAL,  FINAL,  FINAL,FINAL, FINAL},
/* s3  */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s4  */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s5  */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s6  */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s7  */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s8  */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s9  */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s10 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s11 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s12 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s13 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s14 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s15 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s16 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s17 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s18 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s19 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s20 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s21 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s22 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
/* s23 */ {FINAL, FINAL,  TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,    TBD,  TBD,   TBD},
};

void testTable();

#endif