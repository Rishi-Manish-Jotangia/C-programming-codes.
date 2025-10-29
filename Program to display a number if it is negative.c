#include <stdio.h>

int main() {
    int number;

    // Ask the user to enter a number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Display the number only if it's negative
    if (number < 0) {
        printf("You entered a negative number: %d\n", number);
    }

    return 0;
}
