#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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

void get_command(const char * src , char *cmd){
    char started = 0;
    int i ;
    for (i = 0; 1; ++i) {
        if(!started && src[i] == ' '){
            continue;
        }
        if(started && src[i] == ' '){
            break;
        }
        started = 1;
        *cmd = src[i];
        cmd++;

    }
    *cmd = 0;
}


void handle_command(char *line,Mab *commands){
    
    char cpy[1024] ;

    char key[1024] ;
    get_command(line,key);
    //printf("%s\n",key);
    // printf("key =%s\nline =%s\nstr = %d\ndir = %s\n",key,line , strcmp(key, "cd"),line + strlen(cpy));
    /*printf("len = %zu\n",strlen("cd"));*/
    if (!strcmp(key,"exit")){
        distroy_mab(commands);
        exit(0);
    }else if (!strcmp(key, "cd"))
    {
        chdir(line + strlen(key) + 1);
        return;
    }
    

    char *value = retreave(commands , key);
    if (value == NULL)
    {
        fprintf(stderr,"Invalid command \n");
        return;
    }
    else {
        strcpy(cpy,value);
        strcat(cpy , " ");
        strcat(cpy,line + strlen(key) + 1);
        //printf("%s\n",cpy);
        system(cpy);
    }
    
}

