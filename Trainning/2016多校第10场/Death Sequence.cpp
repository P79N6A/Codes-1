#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 3e6 + 111;

int ans[MAXN], nxt[MAXN], pre[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, k, q, x; scanf("%d", &t);
    while (t --) {
        scanf("%d%d%d", &n, &k, &q);
        int len = 0;
        nxt[0] = 1;
        for (int i = 1; i <= n; ++i) {
            nxt[i] = i + 1;
            pre[i] = i - 1;
        }
        while (1) {
            int cnt = 0, p = 0;
            if (nxt[p] == n + 1) break;
            while (p != n + 1) {
                ++cnt;
                if ((cnt - 0) % k == 0) {
                    ans[++len] = p;
                    pre[nxt[p]] = pre[p];
                    nxt[pre[p]] = nxt[p];
                }
                p = nxt[p];
            }
        }
        while (q --) {
            scanf("%d", &x);
            printf("%d\n", ans[x]);
        }
    }
    return 0;
}
