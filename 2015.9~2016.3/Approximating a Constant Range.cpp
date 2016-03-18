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
const int MAXN = 1e5 + 111;

int p[MAXN];

int main()
{
    int n, x, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        if (p[x - 1] > p[x + 1]) ans = max(ans, i - max(p[x - 2], p[x + 1]));
        else ans = max(ans, i - max(p[x - 1], p[x + 2]));
        p[x] = i;
    }
    printf("%d\n", ans);
    return 0;
}
