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
const int MAXN = 21;

// cnt[i][j]:第i位异或后，对全体第j位和的影响
ll cnt[MAXN][MAXN], ans;
int d[MAXN], mxx, x;

void dfs(int i, int tx, ll sum) {
    if (i == mxx) {
        if (ans > sum || (ans == sum && tx < x)) {
            ans = sum;
            x = tx;
        }
    }
    else {
        for (d[i] = 0; d[i] < 2; ++d[i]) {
            ll nsum = sum + cnt[i][i];
            for (int j = 0; j < i; ++j) {
                // 如果前方异或过，后方没异或过，异或值为正，此时取相反数，否则异或异或抵消，取原数
                if (d[i] ^ d[j]) {
                    nsum -= cnt[i][j];
                }
                else nsum += cnt[i][j];
            }
            dfs(i + 1, tx | (d[i] << i), nsum);
        }
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, a, b; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &a);
        memset(cnt, 0, sizeof cnt);
        for (int i = 1; i < n; ++i) {
            scanf("%d", &b);
            int h = 20;
            while (h >= 0 && ~(a ^ b) >> h & 1) --h;
            int mi = min(a, b);
            int mx = max(a, b);
            for (int j = 0; j <= h; ++j) {
                cnt[h][j] += (mx >> j & 1) - (mi >> j & 1);
            }
            a = b;
        }
        mxx = 20;
        while (mxx > 0 && !cnt[mxx - 1][mxx - 1]) --mxx;
        for (int i = 0; i <= mxx; ++i) {
            for (int j = 0; j <= i; ++j) {
                cnt[i][j] <<= j;
            }
        }
        ans = 1e18;
        dfs(0, 0, 0);
        printf("%d %I64d\n", x, ans);
    }
    return 0;
}
