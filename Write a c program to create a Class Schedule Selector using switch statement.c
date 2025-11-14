#include <stdio.h>

int main() {
    int day;

    printf("Enter the period: ");
    scanf("%d", &day);  // Fixed: replaced %day with &day

    printf("\nClass for the selected period:\n");

    switch (day) {
        case 1:
            printf("9:00 AM - 10:00 AM: Mathematics\n");
            break;
        case 2:
            printf("10:00 AM - 11:00 AM: Computer Organisation\n");
            break;
        case 3:
            printf("11:00 AM - 12:00 PM: Linux\n");
            break;
        case 4:
            printf("1:00 PM - 2:00 PM: Physics\n");
            break;
        case 5:
            printf("2:00 PM - 3:00 PM: Computer Programming in C\n");
            break;
        case 6:
        case 7:
            printf("No classes scheduled\n");
            break;
        default:
            printf("Invalid period number entered. Please enter a number between 1 and 5.\n");
            break;
    }

    return 0;  // Fixed: replaced colon with semicolon
}
