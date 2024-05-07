// Écrire un programme qui déclare deux variables numériques. Utiliser des
// pointeurs pour échanger les valeurs de ces deux variables sans utiliser de variable temporaire.

# include <stdio.h>

int main() {
    int first_value = 4;
    int second_value = 17;
    int *ptr1 = &first_value;
    int *ptr2 = &second_value;

    printf (" Valeur 1 : %d            Valeur 2 : %d\n", first_value, second_value);

    *ptr1 = *ptr1 + *ptr2 ;
    *ptr2 = *ptr1 - *ptr2 ;
    *ptr1 = *ptr1 - *ptr2 ;

    printf (" Valeur 1 : %d            Valeur 2 : %d\n", first_value, second_value);

    return 0;
}
