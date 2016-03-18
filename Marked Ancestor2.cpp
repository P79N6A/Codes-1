#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

int p[MAXN];
int qt[MAXN], qv[MAXN], mark[MAXN];
int t;

int find(int x) {
    return mark[x] < t ? x : p[x] = find(p[x]); // 小于则说明在查询之前已经染过颜色
}

int main()
{
    int n, q;
    while (~scanf("%d%d", &n, &q) && (n | q)) {
        for (int i = 2; i <= n; ++i) {
            scanf("%d", p + i);
            mark[i] = INF;
        }

        int cnt = 0, x;
        char op[2];
        for (int i = 1; i <= q; ++i) {
            scanf("%s%d", op, &x);
            if (op[0] == 'M') mark[x] = min(mark[x], i); // 记录最早染色时间
            else {
                qt[cnt] = i;
                qv[cnt++] = x;
            }
        }

        ll ans = 0;
        while (cnt --) {
            t = qt[cnt]; // 查询发生的时间
            ans += find(qv[cnt]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
