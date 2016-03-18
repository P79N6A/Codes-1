#include <iostream>
#include <cstdio>
#include <algorithm>
const int MAXN = 1e5 + 11;
typedef long long ll;

ll parent[MAXN];

ll find(ll v)
{
    return parent[v] == v ? v : find(parent[v]);
}

int main() {
    int n, q;
    while(~scanf("%d%d", &n, &q) && n && q)
    {
        parent[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            scanf("%lld", &parent[i]);
        }
        ll ans = 0;
        for (int i = 0; i < q; ++i)
        {
            char op[2];
            int v;
            scanf("%s%d",op, &v);
            if (op[0] == 'Q')
                ans += find(v);
            else {
                parent[v] = v;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
