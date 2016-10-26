#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int num[3000];

int main() {
    int x, n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        ++num[x];
    }
    int sum = 0;
    for (int i = 0; i < 1001; ++i) {
        if (num[i]) {
            printf("%d\n", n - sum);
            sum += num[i];
        }
    }
    return 0;
}