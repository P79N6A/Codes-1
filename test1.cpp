#include<stdio.h>

bool isleap(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return true;
    }
    return false;
}

int main() {
    int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month, year, ans;
    scanf("%d,%d", &year, &month);
    if (month == 2 && isleap(year)) {
        ans = 29;
    }
    else ans = day[month - 1];
    printf("%d 年 %d 月有 %d 天\n", year, month, ans);
    return 0;
}
