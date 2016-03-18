#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int count(int x, int sum)
{
    int ret = 1;
    for (int i = sum; i > sum - x; --i)
        ret *= i;
    for (int i = x; i > 1; --i)
        ret /= i;
    return ret;
}

int main() {
    char a[11], b[11];
    scanf("%s %s", a, b);
    int add1 = 0, sub1 = 0, add2 = 0, sub2 = 0;
    for (int i = 0; i < strlen(a); ++i)
    {
        if (a[i] == '+')
            ++add1;
        else ++sub1;
        
        if (b[i] == '+')
            ++add2;
        else if (b[i] == '-')
            ++sub2;
    }
    double ans = 0;
    if (sub2 > sub1 || add2 > add1)
        printf("%.12f\n", ans);
    else{
        int need = add1 - add2, lef = strlen(a) - add2 - sub2;
        int sum = 0;
        for (int i = 1; i <= lef; ++i)
            sum += count(i, lef);
        ans = (double)count(need, lef) / (sum + 1);
        printf("%.12f\n", ans);
    }
    return 0;
}
