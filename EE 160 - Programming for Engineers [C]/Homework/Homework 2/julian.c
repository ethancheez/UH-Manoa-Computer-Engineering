#include "days.h"

int julian_date(int day, int month, int year) {

    int totalDays = 0;

    for(int i = 1; i < month; i++) {
        totalDays += days_in_month(i, year);
    }
    totalDays += day;

    return totalDays;
}
