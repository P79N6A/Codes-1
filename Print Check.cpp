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

int mp[MAXN][MAXN];
int col[MAXN], row[MAXN];
int colop[MAXN], rowop[MAXN];

int main()
{
    int n, m, k, op, x, c;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; ++i) {
        scanf("%d%d%d", &op, &x, &c);
        if (op == 1) {
            row[x] = c;
            rowop[x] = i;
        }
        else {
            col[x] = c;
            colop[x] = i;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (rowop[i] < colop[j]) printf("%d", col[j]);
            else printf("%d", row[i]);
            if (j < m) putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}
