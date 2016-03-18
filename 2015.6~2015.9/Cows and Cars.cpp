#include<iostream>
#include<cctype>
#include<cstdio>
using namespace std;

int main()
{
    double a, b, c;
    while (cin >> a >> b >> c)
    {
        printf("%.5f\n", (a*b+b*(b - 1))/(a + b)/(a + b - c - 1));
    }
    return 0;
}
