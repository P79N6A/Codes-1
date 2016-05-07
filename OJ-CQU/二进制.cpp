#include<cstdio>

int main()
{
    int t, n; scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        printf("%d\n", __builtin_popcount(n));
    }
    return 0;
}
