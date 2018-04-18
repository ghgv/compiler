#include <stdio.h>
#include "lex.h"
#include "token.h"


int a=0;

int main()
{


  lex Lex;
  token t=new token();
  while((t=Lex.scan()).tag!=0x0A)
  {
  //  t=Lex.scan();
    if(t.tag==ID)
      printf("%s",t.pos );
    if(t.tag==NUM)
        printf("%i ",t.value );
    if(t.tag=='+')
            printf("+");
    if(t.tag=='-')
            printf("-");
  }


}
