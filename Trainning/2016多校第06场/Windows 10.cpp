/*
 * 上升和休息等价，可以互相调换，所以在最终的时候考虑
 * 贪心每次下降次数，要么刚刚好是差值内的幂，要么是差
 * 值外的，搜索即可。正确性靠感觉。。。写DP对拍
 */
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
const int MAXN = 111;

bool first;
int p2[MAXN], np[MAXN];
inline void init() {
    p2[0] = 1;
    for (int i = 1; i < 31; ++i) {
        p2[i] = p2[i - 1] * 2;
    }
    for (int i = 1; i <= 30; ++i) {
        np[i] = p2[i] - 1;
    }
}

int ans = 0;
void dfs(int p, int q, int add, int step) {
    if (step >= ans) return;
    //printf("(%d %d %d %d)\n", p, q, add, step);
    if (p == q) {
        ans = min(ans, step + add);
        return;
    }
    if (p < q) {
        int dif = q - p;
        if (dif <= add) dfs(q, q, add, step);
        else {
            dfs(q, q, 0, step + dif);
        }
    }
    else {
        int dif = p - q;
        int hx = upper_bound(np + 1, np + 1 + 30, dif) - np;
        int lx = hx - 1, da;
        if (first) da = 0, first = 0;
        else da = 1;
        //prln(np[lx])
        //prln(np[hx])
        dfs(p - np[lx], q, add + da, step + lx);
        dfs(max(0, p - np[hx]), q, add + da, step + hx);
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    init();
    int t, p, q; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &p, &q);
        ans = INF;
        first = 1;
        dfs(p, q, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
