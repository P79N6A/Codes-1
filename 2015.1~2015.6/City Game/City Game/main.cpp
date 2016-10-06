#include <cstdio>
#include <cstring>
const int MAXN = 1010;
char s[5];
int l[MAXN], r[MAXN], h[MAXN];
int k, m, n, tem;

int main() {
    scanf("%d", &k);
    while (k --)
    {
        scanf("%d%d", &m, &n);
        int ans = 0;
        memset(h, 0, sizeof h);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                scanf("%s",s);
                if (s[0] == 'F') ++h[j];
                else h[j] = 0;
                l[j] = r[j] = j;
            }
            for (int j = 0; j < n; ++j)
                while (l[j] >= 1 && h[j] <= h[l[j] - 1])
                    l[j] = l[l[j] - 1];
            for (int j = n - 1; j >= 0; --j)
            {
                while (r[j] < n - 1 && h[j] <= h[r[j] + 1])
                    r[j] = r[r[j] + 1];
                tem = h[j] * (r[j] - l[j] + 1);
                if (ans < tem)
                    ans = tem;
            }
        }
        printf("%d\n",3 * ans);
    }
    return 0;
}