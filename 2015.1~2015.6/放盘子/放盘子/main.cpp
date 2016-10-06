#include <iostream>
#include <cstdio>
#include <cmath>
#define PI 3.14159265358979323846
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int t, cnt = 0;
    scanf("%d",&t);
    while (t --)
    {
        double n;
        double a, r;
        scanf("%lf %lf %lf", &n, &a, &r);
        double d = a / 2.0 / tan(PI / n);
        printf("Case #%d:\n", ++cnt);
        if (d >= r)
            printf("Give me a kiss!\n");
        else printf("I want to kiss you!\n");
    }
    return 0;
}