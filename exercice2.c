# include <stdio.h>

typedef struct person {
    char name[50];
    int age;
    float size;
} person ;

int main () {
    person Person[3] = {{"Martin", 24, 1.93}, {"Emma", 42, 1.68}, {"Sacha", 34, 1.76}} ;
    person *ptr = Person ;

    for(int i = 0; i<3; i++) {
        printf("\nNom : %s \n",(ptr+i)->name);
        printf("Age : %d ans \n", (ptr+i)->age);
        printf("Taille : %.2fm\n", (ptr+i)->size);
    }

    return 0;

}