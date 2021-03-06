#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mem.h"
#include "split.h"

unsigned int  split(char *str,char *tokens)
{
  char *token;
  token = strtok (str,tokens/*" ,.-"*/);
  do 
  {
    unsigned int sz_ = (unsigned int)strlen(token);
    if (!list_started())
    {
      list_init(token,sz_);
    }
    else{
    list_add();
    list_next(token,sz_);
    }
    token = strtok(NULL, " ,.-");

  }while (token != NULL);
  return (list_count());
}

void main (void)
{

  char str[] ="- This, a sample string. My cat named Totoshka!"; 
  printf ("Splitting string \"%s\" into tokens:\n",str);
  
  unsigned int count_ = split(str," ,.-");
  printf ("total parts of string:%d\n",count_);
 for (unsigned int i = 0 ; i < (count_ + 1) ; i++)
 {
   char *out_string;
   get_by_index(i,&out_string); 
   printf("test::%s\n",out_string);
 }
}

