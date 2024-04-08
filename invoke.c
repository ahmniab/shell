#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mab/Mab.h"
#include "analyser.h"

char *strstrip(char *s)
{
    size_t size;
    char *end;

    size = strlen(s);

    if (!size)
        return s;

    end = s + size - 1;
    while (end >= s && *end == ' ')
        end--;
    *(end + 1) = '\0';

    while (*s && *s == ' ')
        s++;

    return s;
}



void handle_command(char *line,Mab *commands){
    
    char cpy[1024] ;
    strcpy(cpy,line);
    strtok(cpy, " ");

    char *key = strstrip(cpy);
    if (!strcmp(key,"exit")){
        distroy_mab(commands);
        exit(0);
    }else if (!strcpy(key , "cd"))
    {
        chdir(line + len(cpy));
    }
    

    char *value = retreave(commands , key);
    if (value == NULL)
    {
        fprintf(stderr,"Invalid command ");
        return;
    }
    else {
        system(line);
    }
    
    
    
    
    
}
