#include "Mab.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void init_mab(Mab *p_mab){
    p_mab->sz = 0 ;
    p_mab->head = NULL;
}

Node* newNode(char* key, char* value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory error\n");
        return NULL;
    }
    strcpy(new_node->key, key);
    strcpy(new_node->value, value);
    new_node->next = NULL;
    return new_node;
}

void push(Mab *p_mab, char* key, char* value) {

    Node* new_node = newNode(key, value);
    new_node->next = p_mab->head;
    p_mab->head = new_node;
}

char* search(Mab *p_mab, char* key) {
    Node* temp = p_mab->head;
    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) {
            return temp->value;
        }
        temp = temp->next;
    }
    return NULL;
}

void printMab(Mab* P_mab) {
    Node *node = P_mab->head ;
    while (node != NULL) {
        printf("Key: %s, Value: %s\n", node->key, node->value);
        node = node->next;
    }
}
