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
#define rson m + 1, r, rt << 1 | 1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 4e6 + 111;

struct E {
    int u, v, w;
    bool operator < (const E &t)const {
        return w < t.w;
    }
}edge[MAXN];

int p[2100];
char s[2100][10];

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%s", &s[i]);
            p[i] = i;
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                edge[cnt].u = i;
                edge[cnt].v = j;
                int sum = 0;
                for (int k = 0; k < 7; ++k) {
                    if (s[i][k] != s[j][k])
                        ++sum;
                }
                edge[cnt++].w = sum;
            }
        }
        sort(edge, edge + cnt);

        int ans = 0;
        for (int i = 0; i < cnt; ++i) {
            int u = find(edge[i].u), v = find(edge[i].v);
            if (u != v) {
                p[u] = v;
                ans += edge[i].w;
            }
        }
        printf("The highest possible quality is 1/%d.\n", ans);
    }
    return 0;
}
