#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

void initDate(struct Date* ptrDate) {
    ptrDate->day = 1;
    ptrDate->month = 1;
    ptrDate->year = 1900;
}

void acceptDateFromConsole(struct Date* ptrDate) {
    printf("Enter day: ");
    scanf("%d", &ptrDate->day);
    printf("Enter month: ");
    scanf("%d", &ptrDate->month);
    printf("Enter year: ");
    scanf("%d", &ptrDate->year);
}

void printDateOnConsole(struct Date* ptrDate) {
    printf("Date: %02d/%02d/%04d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}

int main() {
    struct Date myDate;
    int choice;

    do {
        printf("\n--- Date Menu ---\n");
        printf("1. Initialize Date\n");
        printf("2. Accept Date from Console\n");
        printf("3. Print Date on Console\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initDate(&myDate);
                printf("Date initialized to default (01/01/1900)\n");
                break;
            case 2:
                acceptDateFromConsole(&myDate);
                break;
            case 3:
                printDateOnConsole(&myDate);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
