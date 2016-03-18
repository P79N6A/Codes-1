#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1e5 + 111;

int h[MAXN];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &h[i]);
    int ans = n + n - 1;
    for (int i = 1; i <= n; ++i)
    {
        if (h[i - 1] < h[i])
            ans += h[i] - h[i - 1];
        else if (h[i - 1] > h[i])
            ans += h[i - 1] - h[i];
    }
    printf("%d\n", ans);
    return 0;
}