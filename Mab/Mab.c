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


char* retreave(Mab *p_mab, char* key) {
    Node* temp = p_mab->head;
    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) {
            return temp->value;
        }
        temp = temp->next;
    }
    return NULL;
}
void push(Mab *p_mab, char *key, char* value) {

    char* check_node = retreave(p_mab, key);
    if (check_node != NULL) {
        printf("Error: Key already has a value.\n");
        return;
    }
    else{
        Node* new_node = newNode(key, value);
        new_node->next = p_mab->head;
        p_mab->head = new_node;
        p_mab->sz++;
    }
}


void printMab(Mab* P_mab) {
    Node *node = P_mab->head ;
    while (node != NULL) {
        printf("Key: %s, Value: %s\n", node->key, node->value);
        node = node->next;
    }
}

void distroy_mab(Mab *p_mab) {
    Node *current = p_mab->head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    p_mab->head = NULL;
    p_mab->sz = 0;
}

