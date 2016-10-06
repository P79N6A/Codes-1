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

const int MOD = 1e9 + 7;

ll dp[60][60][2], c[60][60], way[60][60][2];
struct N {
    int n1, n2, sta;
}s;

void init() {
    for (int i = 0; i <= 50; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
}

int main()
{
    int n, k, x;
    init();
    s.n1 = s.n2 = s.sta = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x == 50) ++s.n1;
        else ++s.n2;
    }
    memset(dp, 0, sizeof dp);
    memset(way, 0, sizeof way);
    dp[s.n1][s.n2][0] = way[s.n1][s.n2][0] = 1;
    queue<N> q;
    q.push(s);
    while (q.size()) {
        N cur = q.front(); q.pop();
        for (int j = 0; j <= cur.n1; ++j) {
            if (j * 50 > k) break;
            for (int i = 0; i <= cur.n2; ++i) {
                if (!i && !j) continue;
                if (i * 100 + j * 50 > k) break;
                N temp;
                temp.n1 = s.n1 - cur.n1 + j;
                temp.n2 = s.n2 - cur.n2 + i;
                temp.sta = 1 - cur.sta;

                if (!dp[temp.n1][temp.n2][temp.sta]) {
                    q.push(temp);
                    //cout << tem p.n1 << ' ' << temp.n2 << ' ' << temp.sta << endl;
                    dp[temp.n1][temp.n2][temp.sta] = dp[cur.n1][cur.n2][cur.sta] + 1;
                }

                if (dp[temp.n1][temp.n2][temp.sta] == dp[cur.n1][cur.n2][cur.sta] + 1) {
                    ll t = (((c[cur.n1][j] * c[cur.n2][i]) % MOD) * (way[cur.n1][cur.n2][cur.sta]) % MOD) % MOD;
                    way[temp.n1][temp.n2][temp.sta] = (way[temp.n1][temp.n2][temp.sta] + t) % MOD;
                }
            }
        }
    }
    cout << dp[s.n1][s.n2][1] - 1 << '\n' << way[s.n1][s.n2][1] << '\n';
    return 0;
}
