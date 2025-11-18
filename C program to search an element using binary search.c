#include <stdio.h>
#include <string.h>

#define DAYS 5
#define PERIODS 6

// Function to display the timetable
void displayTimetable(char timetable[DAYS][PERIODS][20], char days[DAYS][10]) {
    printf("\n--- Student Weekly Timetable ---\n");
    for (int i = 0; i < DAYS; i++) {
        printf("%s:\n", days[i]);
        for (int j = 0; j < PERIODS; j++) {
            printf("  Period %d: %s\n", j + 1, timetable[i][j]);
        }
        printf("\n");
    }
}

// Linear search for subject
int linearSearch(char timetable[DAYS][PERIODS][20], char target[]) {
    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < PERIODS; j++) {
            if (strcmp(timetable[i][j], target) == 0) {
                printf("Found '%s' on %d (Day %d, Period %d)\n", target, i * PERIODS + j, i + 1, j + 1);
                return 1;
            }
        }
    }
    return 0;
}

// Binary search (only works on sorted 1D array)
int binarySearch(char arr[][20], int size, char target[]) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(arr[mid], target);
        if (cmp == 0)
            return mid;
        else if (cmp < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    char days[DAYS][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    char timetable[DAYS][PERIODS][20] = {
        {"Math", "English", "Physics", "Chemistry", "PE", "Computer"},
        {"Biology", "Math", "History", "English", "Art", "Physics"},
        {"Chemistry", "Computer", "Math", "English", "PE", "Biology"},
        {"History", "Physics", "Math", "Computer", "English", "Art"},
        {"PE", "Biology", "Chemistry", "Math", "English", "Computer"}
    };

    displayTimetable(timetable, days);

    char subject[20];
    int choice;

    printf("Enter subject to search: ");
    scanf("%s", subject);

    printf("Choose search method:\n1. Linear Search\n2. Binary Search (on sorted list)\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        if (!linearSearch(timetable, subject))
            printf("Subject '%s' not found in timetable.\n", subject);
    } else if (choice == 2) {
        // Flatten and sort timetable for binary search
        char flat[DAYS * PERIODS][20];
        int k = 0;
        for (int i = 0; i < DAYS; i++)
            for (int j = 0; j < PERIODS; j++)
                strcpy(flat[k++], timetable[i][j]);

        // Simple bubble sort
        for (int i = 0; i < k - 1; i++) {
            for (int j = 0; j < k - i - 1; j++) {
                if (strcmp(flat[j], flat[j + 1]) > 0) {
                    char temp[20];
                    strcpy(temp, flat[j]);
                    strcpy(flat[j], flat[j + 1]);
                    strcpy(flat[j + 1], temp);
                }
            }
        }

        int index = binarySearch(flat, k, subject);
        if (index != -1)
            printf("Subject '%s' found at sorted index %d.\n", subject, index);
        else
            printf("Subject '%s' not found in sorted timetable.\n", subject);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
