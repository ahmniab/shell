#ifndef MAB_H_INCLUDED
#define MAB_H_INCLUDED

typedef struct Node{
    char key[100];
    char value[100];

    struct Node * next;
} Node;
typedef struct 
{
    unsigned long sz;
    Node *head ;
}Mab;


void push(Mab *p_mab, char* key, char* value);
char* search(Mab *p_mab, char* key);
void printMab(Mab* P_mab);
void init_mab(Mab *p_mab);

#endif
