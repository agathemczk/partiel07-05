#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int value;
    struct element *next;
} element ;

element* createElement (int value) {
    element* newElement = (element*)malloc(sizeof(element));
    if (newElement == NULL) {
        printf("Erreur dans la création d'un nouvel élément. \n");
        exit(0);
    }

    newElement -> value = value ;
    newElement -> next = NULL;
    return newElement;
}

element *addElement (element* head, int value) {
    element* newElement = createElement(value);
    newElement -> next = head;
    return newElement;
}

element *deleteElement (element* head, int value) {
    if (head == NULL) {
        return NULL;
    }

    if (head -> value == value) {
        element *temp = head -> next;
        free (head);
        return temp;
    }

    element *current = head;
    while (current -> next != NULL && current -> next -> value != value) {
        current = current -> next;
    }

    if (current -> next != NULL) {
        element *temp = current -> next;
        current -> next = current -> next -> next;
        free (temp);
    }
    return(head);
}

void printList (element* head) {
    element*ptr = head;
    while(ptr) {
        printf("%d -> ", ptr -> value);
        ptr = ptr -> next;
    }
    printf("NULL\n");
}

int main() {

    element* head = createElement(10);
    head = addElement(head, 20);
    head = addElement(head, 30);
    head = addElement(head, 40);
    printList(head);

    head = deleteElement(head, 20);
    printList(head);

    return 0;
}
