#ifndef LEX_H
#define LEX_H



#include <stdio.h>
#include "defines.h"
#include "token.h"


class lex: public token{
public:
  char peek;
  int line;
  int k;
  char buffer[30];
  FILE *fp;
  char salida[]="holaMundo";

  lex();
  token scan();
  lex& operator= (const lex& f)
    {
      return *this;
    }

};







#endif
