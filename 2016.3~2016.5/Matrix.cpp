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
const int MAXN = 1111;

int x[MAXN], y[MAXN];
int addx[MAXN], addy[MAXN];
int mp[MAXN][MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    int n, m, q;
    while (t --) {
        scanf("%d%d%d", &n, &m, &q);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                scanf("%d", &mp[i][j]);
        int a, b, c;
        for (int i = 1; i <= n; ++i) x[i] = i, addx[i] = 0;
        for (int i = 1; i <= m; ++i) y[i] = i, addy[i] = 0;
        for (int i = 0; i < q; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            if (a == 1) {
                swap(x[b], x[c]);
            }
            else if (a == 2) {
                swap(y[b], y[c]);
            }
            else if (a == 3) {
                addx[x[b]] += c;
            }
            else addy[y[b]] += c;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                printf("%d", mp[x[i]][y[j]] + addx[x[i]] + addy[y[j]]);
                if (j != m) putchar(' ');
                else putchar('\n');
            }
        }
    }
    return 0;
}
