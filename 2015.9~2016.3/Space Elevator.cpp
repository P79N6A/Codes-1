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
const int MAXN = 4e4 + 111;

int dp[MAXN];
struct B {
    int h, a, c;
    bool operator < (const B &t)const {
        return a < t.a;
    }
}b[456];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int k; scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d%d%d", &b[i].h, &b[i].a, &b[i].c);
    }
    sort(b, b + k);

    dp[0] = 0;
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        for (int j = b[i].c; j >= 1; --j){
            for (int k = b[i].a; k >= b[i].h; --k){
                dp[k] = max(dp[k], dp[k - b[i].h] + b[i].h);
                if (dp[k] && dp[k] > ans) ans = dp[k];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
