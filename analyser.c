#include <stdio.h>
#include <stdlib.h>
#include "Mab/Mab.h"

#define close do(goto close;);
#define CONF "conf/cmd.conf"

typedef struct
{
    char dos[100];
    char bash[100];
}Line;

void is_syntax_valid(){
    FILE *conf_file = fopen(CONF , "r");
    if (!conf_file)
    {
        fprintf(stderr , "NO CONF FILE");
        exit(1);
    }

    char key = 0 , space = 0 , val = 0 , eof = 1;
    size_t lines = 1 ;
    char curr = (char) fgetc(conf_file);

    while (eof)
    {
        switch (curr)
        {
            case -1 :
                if (key  && (!val))
                {
                    fprintf(stderr , "conf file : syntax err in line :%d no value",lines);
                    fclose(conf_file);
                    exit(1);
                }
                else eof = 0;
                break;
            case ' ':
                if (key && val) space ++;
                else if (key) space = 1 ;
                break;
            case '\n':
                if (key  && (!val))
                {
                    fprintf(stderr , "conf file : syntax err in line :%d no value",lines);
                    fclose(conf_file);
                    exit(1);
                }else{
                    lines++ ;
                    key = 0 ;
                    val = 0 ;
                    space=0 ;
                }
                break;

            default:
                if (space == 1) val = 1;
                else if (space > 1) {
                    fprintf(stderr , "conf file : syntax err in line :%d",lines);
                    fclose(conf_file);
                    exit(1);
                }
                else key = 1;
                break;
        }
        curr = (char) fgetc(conf_file);
    }

    fclose(conf_file);

}

void extract_lines(Mab *commands){

    Line line;
    FILE *conf_file = fopen(CONF, "r");
    is_syntax_valid(conf_file);


    while(!feof(conf_file))
    {
        fscanf(conf_file ,"%s %s ",line.dos , line.bash);
        push(commands,line.dos,line.bash);
    }
    //printf("%s\n",search(commands ,"dir"));

    fclose(conf_file);
}

// int main(){
//     extract_lines();

// }