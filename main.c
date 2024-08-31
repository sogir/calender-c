#include <stdio.h>

int getFirstDayOfTheYear(int year) {
    int day = (year * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
    return day;
}

int main() {
    char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, j, totalDays, weekDay = 0, spaceCounter, year;

    printf("Enter your favorite year: ");
    scanf("%d", &year);

    // Check if it is a leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[1] = 29;
    }

    // Get the first day of the year
    weekDay = getFirstDayOfTheYear(year);

    for (i = 0; i < 12; i++) {
        printf("\n\n------------%s-------------\n", months[i]);
        printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        for (spaceCounter = 1; spaceCounter <= weekDay; spaceCounter++) {
            printf("     ");
        }

        totalDays = daysInMonth[i];

        for (j = 1; j <= totalDays; j++) {
            printf("%5d", j);

            weekDay++;
            if (weekDay > 6) {
                weekDay = 0;
                printf("\n");
            }
        }
    }

    return 0;
}
