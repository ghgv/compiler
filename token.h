#ifndef TOKEN_H
#define TOKEN_H



class token{
  public:
    int id;
    int value;
    int tag;
    void *pos;

    token();
    token(int peek);

};


#endif
