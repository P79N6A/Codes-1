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
const int MAXN = 2e5 + 111;

int h[MAXN], w[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, hmax = 0, hsmax = 0, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &w[i], &h[i]);
        sum += w[i];
        if (h[i] > hmax) {
            if (hmax > hsmax) hsmax = hmax;
            hmax = h[i];
        }
        else if (h[i] == hmax) hsmax = hmax;
        else if (h[i] > hsmax) hsmax = h[i];
    }

    for (int i = 0; i < n; ++i) {
        if (h[i] == hmax) printf("%d", (sum - w[i]) * hsmax);
        else printf("%d", (sum - w[i]) * hmax);
        if (i == n - 1) putchar('\n');
        else putchar(' ');
    }
    return 0;
}
