#ifndef MAB_H_INCLUDED
#define MAB_H_INCLUDED


typedef struct Node {
    char key[100];
    char value[100];

    struct Node* next;
} Node;

#endif
