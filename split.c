#ifndef _SPLIT_EXAMPLE__
#define _SPLIT_EXAMPLE__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mem.h"
#include "split.h"
unsigned int  split(char *str,char *tokens)
{
  char *token;
  //token = strtok (str,tokens/*" ,.-"*/);
  do 
  {
    unsigned int sz_ = (unsigned int)strlen(token);
    if (!list_started())
    {
      list_init(token,sz_);
    }
    else
    {
      list_add();
      list_next(token,sz_);
    }
    token = strtok(NULL, " ,.-");

  }while (token != NULL);
  return (list_count());
}

#endif