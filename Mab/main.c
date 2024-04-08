#include <stdio.h>
#include <stdlib.h>
#include "Mab.h"

int main()
{
        Node* head = NULL;


    push(&head, "two", "2");
    push(&head, "one", "1");


    push(&head, "four", "4");
    push(&head, "three", "3");


    printf("Linked List: \n");
    printList(head);

    char* value = search(head, "one");
    if (value) {
        printf("\nValue of key 'one': %s\n", value);
    } else {
        printf("\nKey '6' not found.\n");
    }




    return 0;
}
