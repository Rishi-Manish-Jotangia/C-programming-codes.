#include <stdio.h>

int main() {
    int num1, num2;

    // Prompt user to enter two numbers
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Compare the numbers
    if(num1 > num2) {
        printf("%d is greater than %d\n", num1, num2);
        printf("%d is smaller than %d\n", num2, num1);
    } else if(num1 < num2) {
        printf("%d is greater than %d\n", num2, num1);
        printf("%d is smaller than %d\n", num1, num2);
    } else {
        printf("Both numbers are equal: %d = %d\n", num1, num2);
    }

    return 0;
}
