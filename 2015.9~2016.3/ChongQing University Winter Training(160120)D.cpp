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
const int MAXN = 1e3 + 111;

int mp[MAXN][MAXN];
int row[MAXN], col[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) row[i] = i;
    for (int j = 1; j <= m; ++j) col[j] = j;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &mp[i][j]);
        }
    }

    char op[2];
    int a, b;
    while (k --) {
        scanf("%s%d%d", op, &a, &b);
        if (op[0] == 'r') {
            swap(row[a], row[b]);
        }
        else if (op[0] == 'c') {
            swap(col[a], col[b]);
        }
        else printf("%d\n", mp[row[a]][col[b]]);
    }
    return 0;
}
