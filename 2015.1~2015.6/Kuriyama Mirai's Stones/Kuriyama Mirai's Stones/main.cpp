#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
typedef long long ll;
using namespace std;

const int MAXN = 1e5 + 111;

ll dp1[MAXN], dp2[MAXN];
ll v[MAXN];


int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", v + i);
        dp1[i] = v[i] + dp1[i - 1];
    }
    sort(v + 1, v + 1 + n);
    for (int i = 1; i <= n; ++i)
        dp2[i] = v[i] + dp2[i - 1];
    int m; scanf("%d", &m);
    while (m --)
    {
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        if (op == 1)
            printf("%lld\n", dp1[r] - dp1[l - 1]);
        else printf("%lld\n", dp2[r] - dp2[l - 1]);
    }
    return 0;
}
