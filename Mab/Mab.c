#include "Mab.h"
#include <stdio.h>
#include<stdlib.h>

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

void push(Node** head, char* key, char* value) {
    Node* new_node = newNode(key, value);
    new_node->next = *head;
    *head = new_node;
}

char* search(Node* head, char* key) {
    Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) {
            return temp->value;
        }
        temp = temp->next;
    }
    return NULL;
}

void printList(Node* node) {
    while (node != NULL) {
        printf("Key: %s, Value: %s\n", node->key, node->value);
        node = node->next;
    }
}
