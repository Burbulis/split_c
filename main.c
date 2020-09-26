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
    list_add();
    list_next(token,sz_);

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
  char *out_;
  get_by_index(4,&out_string); 
  printf("test::%s\n",out_string);

}

