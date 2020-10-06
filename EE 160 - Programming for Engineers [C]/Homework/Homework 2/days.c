#include"leap.h"

int days_in_month(int month, int year){
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (month == 2 && is_leap(year))
        return 29;
    else
        return 28;
}
