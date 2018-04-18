#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "lex.h"
#include "num.h"
#include "word.h"



lex::lex(){
  peek=' ';
  line=0;
  k=0;
  fp=fopen("programa.c","r");
  printf("Inside lex constr\n");
  fflush(stdout);
  if(fp==NULL)
    {
      printf("File Not found\n" );
    }

}

 token lex::scan(){
  k=0;
  for(;;peek=getc(fp))
  {
    //printf("peek %02x",peek);fflush(stdout);
    if(peek==' '|| peek == '\t') continue;
    else if(peek=='\n') line++;
    else break;
  }
  if(isdigit(peek))
  {
    int v=0;
    char arr[] = "X";
    //printf("isdigit 0x%02x\n",(char) peek);fflush(stdout);
    do{
      arr[0]=(char)peek;
      v=10*v+atoi(arr);
      peek=getc(fp);
    }while(isdigit(peek));
  //printf("v= %i\n",v);
  fflush(stdout);
  num *g= new num(v);
  return *g;
  }
  if(isalpha(peek)){
  do{
    //printf("isalpha 0x%02x\n",(char) peek);fflush(stdout);
    buffer[k++]=peek;
    peek=getc(fp);
  }while(isalpha(peek) || isdigit(peek));
  //buffer[k++]=peek;
  buffer[k]='\0';
  word *w= new word(ID,buffer);
  return *w;
  }
  //printf("itoken 0x%02x\n",(char) peek);fflush(stdout);
  token *t= new token(peek);
  peek=' ';
  return *t;
}
