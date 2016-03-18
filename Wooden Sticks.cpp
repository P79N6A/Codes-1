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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 5e3 + 111;

bool used[MAXN];
struct S {
    int l, w;
    bool operator < (const S &t)const {
        if (l != t.l)
            return l < t.l;
        else return w < t.w;
    }
}s[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int kase, n;
    scanf("%d", &kase);
    while (kase --) {
        scanf("%d", &n);
        memset(used, 0, sizeof(bool) * (n + 1));
        for (int i = 0; i < n; ++i) scanf("%d%d", &s[i].l, &s[i].w);

        sort(s, s + n);

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                ++ans;
                used[i] = 1;
                //pr(s[i].l);pr(s[i].w);
                int w = s[i].w;
                for (int j = i + 1; j < n; ++j) {
                    if (!used[j] && s[j].w >= w) used[j] = 1, w = s[j].w;
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
