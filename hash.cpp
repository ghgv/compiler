#include "hash.h"
#include <string>

typedef struct
{
     std::string name; // for the filename

}hashd;

hashd hashArray[MAX_LEN]; // tentative

int returnHash(std::string s)
{
    // A simple hashing, no collision handled
    int sum=0,index=0;
    for(std::string::size_type i=0; i < s.length(); i++)
    {
        sum += s[i];
    }
    index = sum % MAX_LEN;
    return index;
}
