#ifndef WORD_H
#define WORD_H

#include "token.h"
#include "defines.h"


class word: public token{

public:
  unsigned char *palabra;
  word(int id,unsigned char  *c);

};


#endif
