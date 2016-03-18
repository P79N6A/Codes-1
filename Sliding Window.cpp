#include<stdio.h>

int a[1000100], q[1000100];

int main()
{
    int n, k;
    while (~scanf("%d%d", &n, &k)) {
        int l = 0, r = 0, i, j;
        for (i = 0; i < n; ++i) scanf("%d", &a[i]);
        q[r] = 0;
        for (i = 1; i < k; ++i) {
            while (r >= 0 && a[q[r]] >= a[i]) --r;
            q[++r] = i;
        }
        printf("%d", a[q[l]]);

        for (i = k; i < n; ++i) {
            while (r >= l && a[q[r]] >= a[i]) --r;
            q[++r] = i;
            while (i - q[l] >= k) ++l;
            printf(" %d", a[q[l]]);
        }
        putchar('\n');

        l = r = 0;
        q[r] = 0;
        for (i = 1; i < k; ++i) {
            while (r >= 0 && a[q[r]] <= a[i]) --r;
            q[++r] = i;
        }
        printf("%d", a[q[l]]);
        for (i = k; i < n; ++i) {
            while (r >= l && a[q[r]] <= a[i]) --r;
            q[++r] = i;
            while (i - q[l] >= k) ++l;
            printf(" %d", a[q[l]]);
        }
        putchar('\n');
    }
    return 0;
}
