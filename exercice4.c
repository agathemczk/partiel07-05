#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Car {
    char brand[30];
    char model[30];
    int year;
} Car ;

typedef struct element {
    Car car;
    struct element *next;
} element ;

element* createElement (Car car) {
    element* newElement = (element*)malloc(sizeof(element));
    if (newElement == NULL) {
        printf("Erreur dans la création d'un nouvel élément. \n");
        exit(0);
    }

    newElement -> car = car ;
    newElement -> next = NULL;
    return newElement;
}

element *addElement (element* head, Car car) {
    element* newElement = createElement(car);
    newElement -> next = head;
    return newElement;
}

element *deleteCarByModel (element* head, char* model) {
    if (head == NULL) {
        return NULL;
    }

    if(strcmp (head -> car.model, model) ==0) {
        element* temp = head -> next;
        free (head);
        return temp;
    }

    element* current = head;
    while ( current -> next != NULL && strcmp(current -> next -> car.model, model) != 0) {
        current = current -> next;
    }

    if (current -> next != NULL) {
        element* temp = current -> next;
        current -> next =  current -> next -> next;
        free (temp) ;
    }
    return (head);
}

void printList (element* head) {
    element*ptr = head;
    while(ptr) {
        printf("\n Marque : %s\n",ptr -> car.brand);
        printf(" Modèle : %s\n",ptr -> car.model);
        printf(" Année : %d\n",ptr -> car.year);
        ptr = ptr -> next;
    }
}

int main() {

    Car first_car = {"Peugeot", "208", 2018};
    Car second_car = {"Dacia", "Sandero", 2020};
    Car third_car = {"Honda","Civic",2021};

    element* head = createElement(first_car);
    head = addElement(head, second_car);
    head = addElement(head, third_car);

    printList(head);
    printf("\n//////////////////////   supression de la 208   //////////////////////\n");

    head = deleteCarByModel(head,"208");
    printList(head);

    return 0;
}
